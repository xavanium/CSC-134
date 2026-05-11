# Design Document — Project 4: ComplexLab (v2, scaled-down)

**Name:** Xavanium
**Track:** A
**Project Title:** ComplexLab — A stdout ASCII Argand-plane visualizer
**One-sentence pitch:** A terminal program that prompts the user for the real and imaginary parts of complex numbers and plots them as vectors on an ASCII Argand plane.

---

## 0. Origin & Motivation

This project grows out of `complexComparison.cpp`, a small program that took two complex numbers and compared their magnitudes. ComplexLab keeps the spirit of "type in a number, see something happen" and adds the part that was missing: actually *seeing* the number as a point and a vector on the complex plane.

**Scope note (v2):** The earlier draft of this design aimed at a full ncurses workspace with persistence, geometric overlays, and pan/zoom. That scope blew up during the first build attempt. This v2 design intentionally cuts back to one core interaction — input a number, see it plotted — and leaves the larger pieces as stretch goals.

---

## 1. The Problem

Complex numbers are hard to picture without a visualization. A student who types `3` and then `4` should immediately see the vector from the origin to (3, 4) on the plane, with axes labeled, so the abstract pair `(a, b)` becomes a concrete arrow.

---

## 2. State Inventory

| Data | Type | What Changes It |
|---|---|---|
| Entered numbers | `std::vector<ComplexNumber>` | User adds one per loop iteration |
| Loop control flag | `bool running` | Set to false when user enters `q` at the real-part prompt |
| Plot grid dimensions | `const int` width/height | Fixed at compile time (e.g., 61 cols × 21 rows) |
| Auto-fit scale | `double` (per replot) | Recomputed from current vector each time the plot renders |

Two variables (the number vector and `running`) change during program execution, which clears the C-tier "state tracking" bar. The vector itself is the meaningful data structure required for B tier.

---

## 3. Function / Component Map

### `ComplexNumber` class

| Member | What It Does | Returns |
|---|---|---|
| `ComplexNumber(real, imag)` | Constructor | object |
| `real() const`, `imag() const` | Component accessors | double |
| `magnitude() const` | √(r² + i²) via `std::hypot` | double |
| `argument() const` | `std::atan2(imag, real)` | double |
| `toString() const` | Formats as `"3 + 4i"` (handles negative imag) | string |

### Free functions

| Function | What It Does | Returns |
|---|---|---|
| `main()` | Greets, runs input/plot loop, returns 0 on `q` | int |
| `promptForNumber(out)` | Prompts real then imag; validates each; returns false on `q` | bool |
| `readDouble(prompt)` | Loops on `cin.fail()`, re-prompts on bad input | double |
| `renderPlot(numbers, w, h)` | Builds and prints the ASCII grid for all numbers | void |
| `autoScale(numbers, w, h)` | Returns units-per-cell that fits all current numbers + padding | double |
| `drawLine(grid, x0, y0, x1, y1, ch)` | Bresenham line into the grid buffer | void |

That's 5 class members + 6 free functions = **11 components**, well above B tier's "5+" threshold, with clean separation: data (`ComplexNumber`), input (`prompt*`, `readDouble`), rendering (`renderPlot`, `autoScale`, `drawLine`), composition (`main`).

---

## 4. User Flow

1. Run `./complexlab`.
2. Program greets and shows brief instructions: *"Enter complex numbers; each is plotted on the Argand plane. Type `q` at the real-part prompt to quit."*
3. Prompt: `Real part (or 'q' to quit): `. User types `3`.
4. Prompt: `Imaginary part: `. User types `4`.
5. Number is appended to the vector. The full plot is re-rendered, showing the axes, all numbers as vectors from origin, and a marker (`*` or a digit) at each tip. A legend prints below: `[0] 3 + 4i  |z|=5.00`.
6. Loop back to step 3.
7. User types `q` at the real prompt → loop exits, program ends.

### Key branches
- **Empty input loop** (user quits immediately with `q`) → exit cleanly without crashing.
- **Bad input** (letters where a number is expected) → `readDouble` clears the stream and re-prompts.
- **`q` at the *imaginary* prompt** → treated as bad input and re-prompts (quit is only at the real prompt, so the input flow stays predictable).
- **Number at origin (0 + 0i)** → still rendered: marker at origin, no line drawn (length 0).
- **All-zero plot** → axes still draw; scale falls back to default (1 unit per cell).

---

## 5. What Could Go Wrong

| Risk | Plan |
|---|---|
| User types letters where a number is expected | `readDouble` checks `cin.fail()`, clears stream, ignores rest of line, re-prompts |
| User enters very large numbers (1e100) | `std::hypot` is overflow-safe; `autoScale` keeps the grid bounded by recomputing units-per-cell |
| User enters NaN/inf via expressions like `1e9999` | Reject if `!std::isfinite(value)` after read; re-prompt |
| Negative imaginary part formatting (`3 + -4i`) | `toString` prints `"3 - 4i"` when imag < 0 |
| Vector with one zero-length entry | `drawLine` short-circuits when start == end; only the marker is plotted |
| Mixed signs that put origin off-grid | Auto-scale is symmetric: scale chosen so `max(|real|, |imag|)` of any entered number fits in half the grid, keeping origin centered |

---

## 6. What I'll Ask AI to Help With

| Task | Why |
|---|---|
| Bresenham line algorithm for the vector arrows | Well-known algorithm; want a tested reference |
| Sanity-checking `autoScale` math (especially for edge cases) | Easy to get a sign or off-by-one wrong |
| Edge cases for the testing log | AI is good at brainstorming inputs |
| Final code-quality pass (unused includes, naming, consistency) | Cleanup is faster with a reviewer |

---

## 7. What I'll Do Myself (No AI)

**Status for v2:** This restart overrides §7. The previous attempt — where I was writing the `ComplexNumber` class, menu, and viewport math by hand — broke down and led to the wipe. For v2 I've asked AI to scaffold the whole project so I can study a working baseline, then take ownership of changes from there. The reflection section will note this decision honestly.

---

## 8. Scope Check

- Can I build the C-tier version (input numbers, see them plotted) in one session? **Yes.**
- Does every feature connect to the core interaction (visualizing complex numbers)? **Yes.**
- Have I cut anything that's "nice to have"? **Yes** — explicitly cut: ncurses, persistence to file, operation log, arithmetic operators, magnitude circles, parallelograms, rotation arcs, multi-number selection, pan/zoom, named numbers. Many of these may return as stretch goals.

**Stretch goals (only if base ships early):**
- Show a magnitude circle (radius |z|) around the origin for the most-recent number.
- Show an angle arc indicating the argument of the most-recent number.
- Pair-wise sum: enter two numbers, render z₁, z₂, and z₁+z₂ as a parallelogram.
- Save the current list to a text file and reload on launch.

---

## 9. Requirements Analysis

### Functional requirements
- **FR1** Prompt the user for the real part, then the imaginary part, of a complex number.
- **FR2** Validate numeric input and re-prompt on bad input without crashing.
- **FR3** Render a 2D ASCII plot of all entered numbers as vectors from origin, with labeled axes.
- **FR4** Auto-scale the plot so every entered number fits with padding.
- **FR5** Display a legend below the plot listing each number and its magnitude.
- **FR6** Allow the user to quit cleanly by typing `q` at the real-part prompt.

### Non-functional requirements
- **NFR1** Compiles with `g++ -std=c++17 -Wall -Wextra` with zero warnings.
- **NFR2** No crashes on any input — all `cin` failures recovered.
- **NFR3** Runs in any terminal at least as wide as the plot grid (61 cols default).
- **NFR4** No external dependencies beyond the C++17 standard library.

### Out of scope
- ncurses or any TUI library, persistence to disk, arithmetic operations between numbers, multi-number geometric overlays, color, pan/zoom.

---

## 10. OO Design Notes

`ComplexNumber` is the only class. It is intentionally minimal — just the data and the queries the plot needs. Free functions handle input and rendering because they don't share state worth wrapping in a class.

```
ComplexNumber
├── data:    double real_, double imag_
└── queries: real(), imag(), magnitude(), argument(), toString()
```

There are no operators in this version. Adding `operator+` etc. is a stretch goal, not a base requirement.

### File layout
```
M8/
├── design_doc.md
├── src/
│   ├── ComplexNumber.h / .cpp     ← class
│   ├── plot.h / .cpp              ← ASCII rendering + autoScale + drawLine
│   ├── input.h / .cpp             ← readDouble, promptForNumber
│   └── main.cpp                   ← loop
├── Makefile
├── ai_log.md
├── testing_log.md
└── README.md
```

---

## 11. Test Plan

### Input validation
- Type letters at real prompt → re-prompts, no crash.
- Type letters at imaginary prompt → re-prompts, no crash.
- Type `q` at real prompt → program exits cleanly.
- Type `q` at imaginary prompt → re-prompts (quit only valid at real prompt).
- Type a huge number (1e100) → accepted; plot rescales.
- Type `nan` or expressions that produce non-finite values → rejected with a message.

### Rendering
- Enter `3, 4` → vector from origin to upper-right; marker at tip; legend shows `|z|=5.00`.
- Enter `-3, -4` → vector to lower-left; legend shows same magnitude.
- Enter `0, 0` → marker at origin only; no line.
- Enter two numbers with very different magnitudes (e.g., `1,1` then `100,100`) → both fit; smaller one near origin.
- Enter five numbers → all five plotted with distinct markers/labels.

### Build
- `make` on Codespaces produces `./complexlab` with zero warnings.

---

## 12. Portfolio Reflection (filled in at end of project)

*To be written in Week 15. Will cover: what went wrong with the first attempt and what I learned from scrapping it; how cutting scope changed what was possible; the tradeoff between "I write it myself" and "let AI scaffold so I can study a working version"; what I'd add back if I had more time.*

---

## Instructor Approval

*To be filled out during Week 13 check-in:*

- [ ] Scope is appropriate for Track A
- [ ] State inventory is complete
- [ ] Function map shows clear decomposition
- [ ] Student knows what they'll ask AI for
- [ ] Test plan covers the risky parts

**Notes:**
