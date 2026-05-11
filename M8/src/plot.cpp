#include "plot.h"
#include "ComplexNumber.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace {

constexpr int kWidth  = 61;
constexpr int kHeight = 21;
constexpr int kCx     = kWidth  / 2;
constexpr int kCy     = kHeight / 2;

bool isAxisOrEmpty(char c) {
    return c == ' ' || c == '-' || c == '|' || c == '+' || c == '>' || c == '^';
}

void drawLine(std::vector<std::string>& grid,
              int x0, int y0, int x1, int y1, char ch) {
    int dx =  std::abs(x1 - x0);
    int dy = -std::abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;
    while (true) {
        if (x0 >= 0 && x0 < kWidth && y0 >= 0 && y0 < kHeight) {
            if (isAxisOrEmpty(grid[y0][x0])) grid[y0][x0] = ch;
        }
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

// Returns units-per-column. scale_y = 2 * scale_x compensates for the
// terminal cell aspect ratio (~2 tall : 1 wide), so one unit on the real
// axis covers the same on-screen distance as one unit on the imaginary axis.
double autoScaleX(const std::vector<ComplexNumber>& nums) {
    double maxR = 1.0, maxI = 1.0;
    for (const auto& z : nums) {
        maxR = std::max(maxR, std::abs(z.real()));
        maxI = std::max(maxI, std::abs(z.imag()));
    }
    const double halfW = (kWidth  - 1) / 2.0 - 2.0;
    const double halfH = (kHeight - 1) / 2.0 - 2.0;
    double sx_for_real = maxR / halfW;
    double sx_for_imag = maxI / (2.0 * halfH);
    return std::max({sx_for_real, sx_for_imag, 0.2});
}

}  // namespace

void renderPlot(const std::vector<ComplexNumber>& numbers) {
    std::vector<std::string> grid(kHeight, std::string(kWidth, ' '));

    for (int x = 0; x < kWidth;  ++x) grid[kCy][x] = '-';
    for (int y = 0; y < kHeight; ++y) grid[y][kCx] = '|';
    grid[kCy][kCx]          = '+';
    grid[kCy][kWidth - 1]   = '>';
    grid[0][kCx]            = '^';

    if (!numbers.empty()) {
        const double sx = autoScaleX(numbers);
        const double sy = 2.0 * sx;

        std::vector<std::pair<int, int>> endpoints;
        endpoints.reserve(numbers.size());
        for (const auto& z : numbers) {
            int col = kCx + static_cast<int>(std::round(z.real() / sx));
            int row = kCy - static_cast<int>(std::round(z.imag() / sy));
            endpoints.emplace_back(col, row);
            if (col != kCx || row != kCy) {
                drawLine(grid, kCx, kCy, col, row, '.');
            }
        }

        // Lines start at origin and overwrite '+'; restore it before placing
        // markers, so a marker at (0,0) still wins.
        grid[kCy][kCx] = '+';

        for (size_t i = 0; i < endpoints.size(); ++i) {
            int col = endpoints[i].first;
            int row = endpoints[i].second;
            const char marker = (i < 10) ? static_cast<char>('0' + i) : '*';
            if (col >= 0 && col < kWidth && row >= 0 && row < kHeight) {
                grid[row][col] = marker;
            }
        }
    }

    std::cout << "\n  Im\n";
    for (int y = 0; y < kHeight; ++y) {
        std::cout << "  " << grid[y];
        if (y == kCy) std::cout << " Re";
        std::cout << "\n";
    }
    std::cout << "\n";

    if (!numbers.empty()) {
        for (size_t i = 0; i < numbers.size(); ++i) {
            const char marker = (i < 10) ? static_cast<char>('0' + i) : '*';
            std::cout << "  [" << marker << "] " << numbers[i].toString()
                      << "   |z| = " << std::fixed << std::setprecision(2)
                      << numbers[i].magnitude() << "\n";
        }
        std::cout << "\n";
    }
}
