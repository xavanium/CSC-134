#include "plot.h"

// Stubs only. Rendering helpers (drawAxes, drawVector, drawMagnitudeCircle, etc.)
// are tagged for AI assistance per design_doc.md §6.
// worldToScreen / autoFitViewport are user-owned per §7.

ScreenPos worldToScreen(double /*real*/, double /*imag*/, const Viewport& /*vp*/,
                        int /*cols*/, int /*rows*/) {
    // TODO
    return {0, 0};
}

Viewport autoFitViewport(const std::vector<ComplexNumber>& /*nums*/, int /*cols*/,
                         int /*rows*/) {
    // TODO: scan numbers for max |real|, |imag|; pad ~10%; clamp to sane min scale.
    return {0.0, 0.0, 1.0};
}

void drawAxes(WINDOW* /*win*/, const Viewport& /*vp*/) {
    // TODO
}

void drawPoint(WINDOW* /*win*/, const ComplexNumber& /*z*/, const Viewport& /*vp*/,
               char /*marker*/) {
    // TODO
}

void drawVector(WINDOW* /*win*/, const ComplexNumber& /*z*/, const Viewport& /*vp*/) {
    // TODO: Bresenham line from origin to z.
}

void drawMagnitudeCircle(WINDOW* /*win*/, const ComplexNumber& /*z*/,
                         const Viewport& /*vp*/) {
    // TODO: midpoint circle algorithm at radius |z|.
}

void drawParallelogram(WINDOW* /*win*/, const ComplexNumber& /*z1*/,
                       const ComplexNumber& /*z2*/, const Viewport& /*vp*/) {
    // TODO: four edges connecting 0, z1, z1+z2, z2.
}

void drawRotation(WINDOW* /*win*/, const ComplexNumber& /*z1*/,
                  const ComplexNumber& /*z2*/, const Viewport& /*vp*/) {
    // TODO: arc from z1 sweeping by arg(z2), radius scaling by |z2|.
}

void openPlotView(const std::vector<ComplexNumber>& /*numbers*/) {
    // TODO: create plot window, autofit, draw, loop on getch() handling
    //       arrow keys (pan), +/- (zoom), '+' (sum overlay), '*' (product overlay),
    //       'q' (return).
}
