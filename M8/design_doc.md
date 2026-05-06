# Design Document — Project 4: ComplexLab

**Name:** Xavanium
**Track:** A (Badge track)
**Project Title:** ComplexLab — An ncurses Argand Diagram Workspace
**One-sentence pitch:** An interactive terminal workspace where you build, save, and visualize complex numbers on the Argand plane, with geometric visualizations of magnitude, addition, multiplication, and conjugation.

---

## 0. Origin & Motivation

ComplexLab grows out of `complexComparison.cpp`, a 30-line program that took two complex numbers and reported which had the larger magnitude. The original answers a single yes/no question. ComplexLab keeps that comparison as one feature, then asks: *what would make complex numbers feel real?* The answer is seeing them — as points, as vectors, as circles of radius |z|, and as the geometric outcomes of arithmetic.

The expansion is not "more operations bolted on." It is a shift from calculator to workspace: numbers persist, get named, get plotted, get compared, and the operation history is replayable.

---

## 1. The Problem

Complex numbers are abstract for students who haven't seen them visualized. ComplexLab is a tool a math or engineering student could open, type in `z1 = 3 + 4i`, type in `z2 = 1 - 2i`, and *see* the magnitude as a circle, the sum as a parallelogram, the product as a rotation-and-scale on the plane. It saves named numbers and an operation log between sessions, so a study session resumes where it left off.

---

## 2. State Inventory

| Data | Type | What Changes It |
|---|---|---|
| Workspace numbers | `std::vector<ComplexNumber>` | User adds via menu; loaded from save file on startup; deleted via menu |
| Operation log | `std::vector<std::string>` | Every comparison, arithmetic op, and conjugate appends a line; loaded from log file on startup |
| Plot viewport | `struct Viewport { double centerR, centerI; double scale; }` | Auto-fit on plot open; user pan/zoom keys adjust |
| Currently-selected operands | `std::optional<size_t> lhsIdx, rhsIdx` | Set when user picks numbers for an op or plot |
| Workspace file path | `std::string` (default `complexlab_workspace.txt`) | Set at startup, optionally overridden via menu |
| Log file path | `std::string` (default `complexlab_history.log`) | Same |
| ncurses windows | `WINDOW*` (main, plot, status) | Created on init, destroyed on exit |

---

## 3. Function / Component Map

### `ComplexNumber` class (custom, A-tier requirement)

| Member | What It Does | Inputs | Outputs |
|---|---|---|---|
| `ComplexNumber(name, real, imag)` | Constructor | string, double, double | object |
| `magnitude()` | Returns √(r² + i²) using `std::hypot` | none | double |
| `conjugate()` | Returns new ComplexNumber with negated imag | none | ComplexNumber |
| `operator+`, `-`, `*`, `/` | Component-wise / formula-based arithmetic | ComplexNumber | ComplexNumber |
| `toString()` | Formats as `"z1 = 3 + 4i"` | none | string |
| `argument()` | Returns angle (atan2) — used for rotation viz | none | double |

### Free functions / modules

| Function | What It Does | Inputs | Outputs |
|---|---|---|---|
| `main()` | Init ncurses, load workspace, run menu loop, save & shutdown | argc, argv | int |
| `displayMainMenu()` | Renders main menu in ncurses, returns user choice | none | enum MenuChoice |
| `promptForNumber()` | Hybrid input screen: prompts for name + real + imag with validation | none | ComplexNumber |
| `pickOperand(prompt)` | Lists saved numbers, returns selected index | string | size_t |
| `runArithmetic(op)` | Picks two operands, computes, displays, logs, optionally saves result | enum Op | void |
| `runComparison()` | Picks two operands, displays magnitudes, declares winner, logs | none | void |
| `runConjugate()` | Picks one operand, displays conjugate, logs | none | void |
| `openPlotView()` | Switches to plot ncurses window, handles pan/zoom/quit keys | vector of selected ComplexNumbers | void |
| `drawAxes(win, vp)` | Renders x/y axes with tick labels | window, viewport | void |
| `drawPoint(win, z, vp, marker)` | Plots a single number as a labeled marker | window, ComplexNumber, viewport, char | void |
| `drawVector(win, z, vp)` | Draws a line from origin to z | window, ComplexNumber, viewport | void |
| `drawMagnitudeCircle(win, z, vp)` | Draws circle of radius |z| centered at origin | window, ComplexNumber, viewport | void |
| `drawParallelogram(win, z1, z2, vp)` | Visualizes z1 + z2 geometrically | window, two numbers, viewport | void |
| `drawRotation(win, z1, z2, vp)` | Visualizes z1 * z2 as rotate-and-scale arc | window, two numbers, viewport | void |
| `autoFitViewport(numbers)` | Computes scale to fit all numbers with padding | vector | Viewport |
| `saveWorkspace(path, numbers)` | Writes named numbers to file (`name,real,imag` per line) | path, vector | bool |
| `loadWorkspace(path)` | Parses workspace file; returns empty vector if missing | path | vector<ComplexNumber> |
| `appendLog(path, entry)` | Appends one operation transcript line with timestamp | path, string | void |
| `loadLog(path)` | Reads existing log into memory for "view history" feature | path | vector<string> |
| `validateDouble(prompt)` | ncurses input loop; rejects non-numeric until valid | string | double |
| `validateName(prompt, existing)` | Ensures name is non-empty and unique within workspace | string, vector | string |

That's 6 class members + 22 free functions. Well above A-tier's "5+ functions" with clear separation of concerns: data (ComplexNumber), input/validation, operations, rendering, and persistence.

---

## 4. User Flow

### Main path

1. User runs `./complexlab`. ncurses initializes; `complexlab_workspace.txt` loads if present (otherwise empty workspace).
2. Main menu appears: `[1] Add number  [2] List saved  [3] Run operation  [4] Plot  [5] View history  [6] Save & quit  [7] Quit without saving`.
3. User adds two numbers: `z1 = 3 + 4i`, `z2 = 1 - 2i`.
4. User picks `[3] Run operation`, then `[a] Add  [s] Sub  [m] Mul  [d] Div  [c] Compare magnitudes  [j] Conjugate`.
5. Picks `Compare magnitudes`, picks z1 and z2 from list, sees `|z1| = 5.00, |z2| = 2.24, z1 is larger`. Operation is appended to in-memory log and `complexlab_history.log`.
6. Picks `[4] Plot`, selects z1 and z2 (multi-select). Plot view opens with axes auto-fit; both numbers shown as labeled points + vectors + magnitude circles.
7. From plot view: presses `+` to add a "sum" overlay (parallelogram for z1+z2), `*` for product (rotation arc), `arrow keys` to pan, `=`/`-` to zoom, `q` to return to main menu.
8. Picks `[6] Save & quit`. Workspace and log are flushed; ncurses tears down; program exits.

### Key branches

- **First run, no save file** → `loadWorkspace` returns empty vector; no error shown.
- **Save file is corrupt or partially written** → skip malformed lines, show status-bar warning `"Skipped N malformed lines from workspace"`, continue.
- **User picks operation requiring two operands but only one number is saved** → show message `"Add another number first"`, return to menu.
- **Division by zero** (`z / 0+0i`) → catch before arithmetic; show `"Cannot divide by zero"`; do not log.
- **Name collision** when adding (`z1` already exists) → re-prompt with `"Name already in use; choose another"`.
- **Terminal too small for plot** (e.g., < 40×20) → show message in plot view, return to menu without crashing.
- **Plot with all-zero numbers** → viewport falls back to default scale (1 unit per ~5 chars).

---

## 5. What Could Go Wrong

| Risk | Plan |
|---|---|
| User enters text where a number is expected | `validateDouble` loops on `cin.fail()`, clears stream, re-prompts with error message |
| Save file missing on first run | `loadWorkspace` checks `ifstream::is_open()`; returns empty vector silently |
| Save file partially corrupt | Parse line-by-line; `try`/`catch` each line; count and report skipped lines |
| Division by zero in `operator/` | Pre-check: if divisor's magnitude is 0 (within epsilon), throw `std::domain_error`; caller shows message instead of logging |
| Very large or very small magnitudes break plot scaling | `autoFitViewport` clamps to a reasonable max scale; status bar shows actual range |
| ncurses crashes mid-program (e.g., terminal resize) | Install `SIGWINCH` handler that re-fetches `getmaxyx` and redraws; fall back gracefully if too small |
| Two numbers given the same name | `validateName` rejects duplicates at input time |
| User force-quits (`Ctrl+C`) without saving | Register `atexit` handler that calls `endwin()` to restore terminal; data loss is acceptable since they chose not to save |
| Floating-point comparison in `compareNumbers` shows "equal" inappropriately | Use epsilon-based comparison (`std::abs(d1 - d2) < 1e-9`) |

---

## 6. What I'll Ask AI to Help With

| Task | Why AI Help Makes Sense |
|---|---|
| ncurses boilerplate (initscr, cbreak, noecho, color pairs, window creation) | I haven't used ncurses before; the API is large and I want correct setup, not to memorize flags |
| Bresenham line algorithm for `drawVector` and `drawParallelogram` edges | Standard algorithm; I want a clean reference implementation rather than reinvent |
| Midpoint circle algorithm for `drawMagnitudeCircle` | Same reason — well-known algorithm, want a tested version |
| Reviewing my `operator*` and `operator/` for arithmetic correctness | Easy to flip a sign in the formula; AI can sanity-check against the standard formulas |
| Suggesting cleaner organization once I have a working prototype | I expect my first cut to have logic mixed across files; want a refactor pass |
| Generating edge-case test inputs for `testing_log.md` | AI is good at brainstorming "what if" cases I'd miss |

---

## 7. What I'll Do Myself (No AI)

1. **The `ComplexNumber` class itself** — constructor, magnitude, conjugate, arithmetic operators, toString. The math here is the learning. I want to write each operator from the formula, not paste one in.
2. **The main menu loop and state management** — deciding how the menu, operands, and plot view flow together is a design call, not a syntax question. AI can review it after; the structure is mine.
3. **The viewport math** (`autoFitViewport`, world-to-screen coordinate transform). This is the kind of geometry problem where doing it myself builds intuition I'll reuse forever.

---

## 8. Scope Check

- Can I build the C-tier version (add numbers, compare magnitudes, plot points only) in one focused session? **Yes.**
- Does every feature in my plan connect to the core interaction (visualizing complex numbers)? **Yes** — every operation has a visualization, every saved number is plottable.
- Have I cut anything that's "nice to have" but not essential? **Yes** — explicitly cut: polar-form input, custom color themes, exporting plots to image files, undo/redo.

**Stretch goals (only if A-tier ships early):**
- Polar input mode (`r∠θ` instead of `a + bi`)
- Color: real axis red, imaginary axis blue, vectors by index color
- "Animate" multiplication: redraw rotation in steps

---

## 9. Requirements Analysis (Badge Track)

### Functional requirements
- **FR1** Input two or more complex numbers via guided prompts with validation.
- **FR2** Compute magnitude, conjugate, sum, difference, product, quotient of any saved pair (or single, for conjugate).
- **FR3** Compare magnitudes of any two saved numbers.
- **FR4** Render a 2D ASCII plot of any subset of saved numbers as points + vectors + magnitude circles.
- **FR5** Render geometric visualizations of addition (parallelogram) and multiplication (rotation/scale).
- **FR6** Persist named numbers to a workspace file across sessions.
- **FR7** Persist an append-only operation log across sessions, viewable from the main menu.
- **FR8** Pan and zoom the plot view via keyboard.

### Non-functional requirements
- **NFR1** Compiles with `g++ -std=c++17 -Wall -Wextra -lncurses` with zero warnings.
- **NFR2** No undefined behavior on bad input — all `cin` failures recovered.
- **NFR3** Workspace file is human-readable plain text (CSV-like).
- **NFR4** Plot renders in any terminal ≥ 40 cols × 20 rows; degrades gracefully below that.
- **NFR5** No memory leaks (all `WINDOW*` paired with `delwin`; `endwin` on every exit path).

### Out of scope
- 3D visualization, GUI windows, exporting to image formats, network features, multiple users.

---

## 10. OO Design Notes (Badge Track)

The only class is `ComplexNumber`. Other code is organized into namespaces / translation units, not classes — overengineering with classes for menu state, file I/O, etc. would muddy a small project.

```
ComplexNumber
├── data:    string name, double real, double imag
├── queries: magnitude(), argument(), conjugate(), toString()
└── ops:     operator+, -, *, /  (return new ComplexNumber)
```

Operators are defined as **non-modifying** member functions returning new objects (immutable-style). Rationale: arithmetic on complex numbers should never mutate operands; this matches mathematical intuition and prevents aliasing bugs.

`name` is part of the object because the workspace concept requires it. A pure-math view would put name in a separate `NamedNumber` wrapper, but the project is about labeled, plottable numbers — coupling name in keeps the API simple.

### File layout
```
project4/
├── design_doc.md
├── src/
│   ├── ComplexNumber.h / .cpp     ← class definition
│   ├── plot.h / .cpp              ← ncurses rendering
│   ├── workspace.h / .cpp         ← save/load/log
│   ├── ui.h / .cpp                ← menu, prompts, validation
│   └── main.cpp                   ← composition root
├── ai_log.md
├── testing_log.md
└── README.md
```

---

## 11. Test Plan (Badge Track)

### Unit-level (manual, recorded in `testing_log.md`)
- `ComplexNumber(3,4).magnitude() == 5.0` (within epsilon)
- `(3+4i) + (1-2i) == 4+2i`
- `(3+4i) * (1-2i) == 11-2i`
- `(3+4i) / (0+0i)` throws `domain_error`
- `(3+4i).conjugate() == 3-4i`

### Input validation
- Type letters when number expected → re-prompts, no crash
- Empty name → re-prompts
- Duplicate name → re-prompts
- Very large numbers (1e100) → no overflow in magnitude (`std::hypot` is safe)

### Persistence
- Fresh run with no files → empty workspace, no error
- Save 3 numbers, quit, relaunch → all 3 reappear
- Manually corrupt one line of workspace file → other lines load, warning shown
- Operation log grows across sessions (append, not overwrite)

### Plot
- Plot single number at origin → no crash, no division by zero in viewport
- Plot two numbers, one tiny (0.001) one huge (1000) → autofit picks the larger; tiny is at origin
- Resize terminal mid-plot → redraws or shows "too small" message
- Plot with sum overlay → parallelogram corners match z1, z2, z1+z2
- Plot with product overlay → rotation arc visible

### Build
- Clean build on Codespaces (`g++ -std=c++17 -Wall -Wextra -lncurses src/*.cpp -o complexlab`)
- Zero warnings

---

## 12. Portfolio Reflection (filled in at end of project)

*To be written in Week 15. Will cover: what I learned about directing AI vs. writing code; what surprised me about ncurses; the moment I rejected an AI suggestion and why; how the design changed from this doc to the final product.*

---

## Instructor Approval

*To be filled out during Week 13 check-in:*

- [ ] Scope is appropriate for badge track
- [ ] State inventory is complete
- [ ] Function map shows clear decomposition
- [ ] Student knows what they'll ask AI for and what they'll do themselves
- [ ] OO design is justified, not bolted on
- [ ] Test plan covers the risky parts

**Notes:**

