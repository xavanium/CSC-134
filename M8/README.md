# ComplexLab

A terminal program that prompts for the real and imaginary parts of complex numbers and plots them as vectors on an ASCII Argand plane.

**Track:** A
**Course:** CSC 134 — Project 4

## Build

Requires `g++` with C++17. No external libraries.

```bash
make
```

## Run

```bash
./complexlab
```

At each iteration the program prompts:

```
Real part (or 'q' to quit):
Imaginary part:
```

The full plot is redrawn after each entry, with every number you've entered shown as a vector from the origin and labeled by index in the legend.

## Files

```
M8/
├── design_doc.md          ← Design (v2, scaled-down) + requirements + test plan
├── src/
│   ├── ComplexNumber.h/.cpp   ← class: real, imag, magnitude, argument, toString
│   ├── plot.h/.cpp            ← ASCII rendering: axes, auto-scale, Bresenham line
│   ├── input.h/.cpp           ← validated stdin prompts
│   └── main.cpp               ← input/plot loop
├── Makefile
├── ai_log.md
├── testing_log.md
├── complexComparison.cpp  ← original M5 program ComplexLab grew out of
└── README.md
```

## What I'm most proud of / what I'd improve

*(filled in at end of project)*
