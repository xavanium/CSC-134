#pragma once

#include <ncurses.h>

#include <vector>

#include "ComplexNumber.h"

struct Viewport {
    double centerR;
    double centerI;
    double scale;  // world units per character cell
};

// World <-> screen coordinate transform. User-owned per §7.
struct ScreenPos { int col; int row; };
ScreenPos worldToScreen(double real, double imag, const Viewport& vp, int cols, int rows);
Viewport autoFitViewport(const std::vector<ComplexNumber>& nums, int cols, int rows);

// Rendering primitives (AI-assisted per §6).
void drawAxes(WINDOW* win, const Viewport& vp);
void drawPoint(WINDOW* win, const ComplexNumber& z, const Viewport& vp, char marker);
void drawVector(WINDOW* win, const ComplexNumber& z, const Viewport& vp);
void drawMagnitudeCircle(WINDOW* win, const ComplexNumber& z, const Viewport& vp);
void drawParallelogram(WINDOW* win, const ComplexNumber& z1, const ComplexNumber& z2,
                       const Viewport& vp);
void drawRotation(WINDOW* win, const ComplexNumber& z1, const ComplexNumber& z2,
                  const Viewport& vp);

// Top-level plot view: blocks until user presses 'q'. Handles pan/zoom keys.
void openPlotView(const std::vector<ComplexNumber>& numbers);
