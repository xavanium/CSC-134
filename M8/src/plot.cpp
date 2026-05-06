#include "plot.h"

#include <cmath>
#include <cstdlib>
#include <string>

// Rendering primitives are AI-assisted (design_doc.md §6).
// worldToScreen / autoFitViewport are user-owned (§7) — left as TODO stubs.

namespace {

constexpr double kPi = 3.14159265358979323846;

void plotChar(WINDOW* win, int col, int row, char ch) {
    int h, w;
    getmaxyx(win, h, w);
    if (col >= 0 && col < w && row >= 0 && row < h) {
        mvwaddch(win, row, col, ch);
    }
}

// Bresenham's line algorithm — generic 8-octant version.
void bresenhamLine(WINDOW* win, int x0, int y0, int x1, int y1, char ch) {
    const int dx = std::abs(x1 - x0);
    const int sx = (x0 < x1) ? 1 : -1;
    const int dy = -std::abs(y1 - y0);
    const int sy = (y0 < y1) ? 1 : -1;
    int err = dx + dy;
    while (true) {
        plotChar(win, x0, y0, ch);
        if (x0 == x1 && y0 == y1) break;
        const int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

}  // namespace

ScreenPos worldToScreen(double /*real*/, double /*imag*/, const Viewport& /*vp*/,
                        int /*cols*/, int /*rows*/) {
    // TODO (user-owned, §7).
    // Map (real, imag) to (col, row), where col grows right and row grows DOWN.
    // Origin should land near (cols/2, rows/2).
    // 1 world unit = 1 / vp.scale character cells (or scale by aspect for rows).
    return {0, 0};
}

Viewport autoFitViewport(const std::vector<ComplexNumber>& /*nums*/, int /*cols*/,
                         int /*rows*/) {
    // TODO (user-owned, §7).
    // Scan numbers for max(|real|, |imag|); pick scale so they fit with ~10% padding.
    // Fall back to scale = 1.0 when all numbers are 0 or list is empty.
    return {0.0, 0.0, 1.0};
}

void drawAxes(WINDOW* win, const Viewport& vp) {
    int h, w;
    getmaxyx(win, h, w);

    const auto origin = worldToScreen(0.0, 0.0, vp, w, h);

    // Horizontal axis (imag == 0): draw across full width at origin's row.
    if (origin.row >= 0 && origin.row < h) {
        for (int c = 0; c < w; ++c) plotChar(win, c, origin.row, '-');
    }
    // Vertical axis (real == 0): draw across full height at origin's col.
    if (origin.col >= 0 && origin.col < w) {
        for (int r = 0; r < h; ++r) plotChar(win, origin.col, r, '|');
    }
    // Origin marker.
    plotChar(win, origin.col, origin.row, '+');
}

void drawPoint(WINDOW* win, const ComplexNumber& z, const Viewport& vp, char marker) {
    int h, w;
    getmaxyx(win, h, w);
    const auto pos = worldToScreen(z.real(), z.imag(), vp, w, h);
    plotChar(win, pos.col, pos.row, marker);
    if (!z.name().empty() && pos.col + 2 < w && pos.row >= 0 && pos.row < h) {
        mvwaddstr(win, pos.row, pos.col + 1, z.name().c_str());
    }
}

void drawVector(WINDOW* win, const ComplexNumber& z, const Viewport& vp) {
    int h, w;
    getmaxyx(win, h, w);
    const auto from = worldToScreen(0.0, 0.0, vp, w, h);
    const auto to = worldToScreen(z.real(), z.imag(), vp, w, h);
    bresenhamLine(win, from.col, from.row, to.col, to.row, '*');
    plotChar(win, to.col, to.row, '#');
}

void drawMagnitudeCircle(WINDOW* win, const ComplexNumber& z, const Viewport& vp) {
    int h, w;
    getmaxyx(win, h, w);
    const auto origin = worldToScreen(0.0, 0.0, vp, w, h);

    const double mag = std::hypot(z.real(), z.imag());
    if (mag <= 0.0 || vp.scale <= 0.0) return;

    // Parametric: avoids edge cases of midpoint algorithm when terminal cells
    // are non-square (a future extension can scale rows differently from cols).
    const int radCells = static_cast<int>(std::round(mag / vp.scale));
    if (radCells < 1) return;

    constexpr int kSteps = 180;
    for (int i = 0; i < kSteps; ++i) {
        const double theta = (2.0 * kPi * i) / kSteps;
        const int col = origin.col + static_cast<int>(std::round(radCells * std::cos(theta)));
        const int row = origin.row - static_cast<int>(std::round(radCells * std::sin(theta)));
        plotChar(win, col, row, '.');
    }
}

void drawParallelogram(WINDOW* win, const ComplexNumber& z1, const ComplexNumber& z2,
                       const Viewport& vp) {
    int h, w;
    getmaxyx(win, h, w);
    const auto p0 = worldToScreen(0.0, 0.0, vp, w, h);
    const auto p1 = worldToScreen(z1.real(), z1.imag(), vp, w, h);
    const auto p2 = worldToScreen(z2.real(), z2.imag(), vp, w, h);
    const auto p3 = worldToScreen(z1.real() + z2.real(), z1.imag() + z2.imag(), vp, w, h);

    bresenhamLine(win, p0.col, p0.row, p1.col, p1.row, ':');
    bresenhamLine(win, p1.col, p1.row, p3.col, p3.row, ':');
    bresenhamLine(win, p3.col, p3.row, p2.col, p2.row, ':');
    bresenhamLine(win, p2.col, p2.row, p0.col, p0.row, ':');
    plotChar(win, p3.col, p3.row, '@');  // sum endpoint
}

void drawRotation(WINDOW* win, const ComplexNumber& z1, const ComplexNumber& z2,
                  const Viewport& vp) {
    int h, w;
    getmaxyx(win, h, w);
    if (vp.scale <= 0.0) return;
    const auto origin = worldToScreen(0.0, 0.0, vp, w, h);

    const double mag1 = std::hypot(z1.real(), z1.imag());
    const double mag2 = std::hypot(z2.real(), z2.imag());
    const double arg1 = std::atan2(z1.imag(), z1.real());
    const double arg2 = std::atan2(z2.imag(), z2.real());

    if (mag1 <= 0.0) return;

    const double magProduct = mag1 * mag2;
    constexpr int kSteps = 40;
    for (int i = 0; i <= kSteps; ++i) {
        const double t = static_cast<double>(i) / kSteps;
        const double angle = arg1 + arg2 * t;
        const double rad = mag1 + (magProduct - mag1) * t;
        const int radCells = static_cast<int>(std::round(rad / vp.scale));
        const int col = origin.col + static_cast<int>(std::round(radCells * std::cos(angle)));
        const int row = origin.row - static_cast<int>(std::round(radCells * std::sin(angle)));
        plotChar(win, col, row, 'o');
    }
}

void openPlotView(const std::vector<ComplexNumber>& numbers) {
    if (numbers.empty()) return;

    int h, w;
    getmaxyx(stdscr, h, w);
    if (h < 20 || w < 40) {
        clear();
        mvaddstr(h / 2, 2,
                 "Terminal too small for plot (need >= 40 cols x 20 rows).");
        mvaddstr(h / 2 + 1, 2, "Resize and try again. Press any key.");
        refresh();
        getch();
        return;
    }

    Viewport vp = autoFitViewport(numbers, w, h);
    bool showSum = false;
    bool showProduct = false;

    while (true) {
        getmaxyx(stdscr, h, w);  // re-read in case of resize
        clear();
        drawAxes(stdscr, vp);
        for (const auto& z : numbers) {
            drawMagnitudeCircle(stdscr, z, vp);
            drawVector(stdscr, z, vp);
            drawPoint(stdscr, z, vp, '*');
        }
        if (showSum && numbers.size() >= 2) {
            drawParallelogram(stdscr, numbers[0], numbers[1], vp);
        }
        if (showProduct && numbers.size() >= 2) {
            drawRotation(stdscr, numbers[0], numbers[1], vp);
        }

        const std::string status =
            "arrows=pan  +/-=zoom  s=sum  m=product  q=back   "
            "scale=" + std::to_string(vp.scale);
        mvaddstr(h - 1, 0, status.c_str());
        refresh();

        const int c = getch();
        switch (c) {
            case 'q': case 'Q': return;
            case KEY_LEFT:  vp.centerR -= vp.scale * 2.0; break;
            case KEY_RIGHT: vp.centerR += vp.scale * 2.0; break;
            case KEY_UP:    vp.centerI += vp.scale * 2.0; break;
            case KEY_DOWN:  vp.centerI -= vp.scale * 2.0; break;
            case '=': case '+': vp.scale *= 0.8; break;
            case '-': case '_': vp.scale *= 1.25; break;
            case 's': case 'S': showSum = !showSum; break;
            case 'm': case 'M': showProduct = !showProduct; break;
            default: break;
        }
    }
}
