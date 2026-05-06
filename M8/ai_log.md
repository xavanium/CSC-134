# AI Interaction Log — ComplexLab

Log of meaningful AI exchanges during the build. Entries are reverse-chronological.

Each entry should answer: **what I asked**, **what AI gave me**, **what I did with it** (accepted / revised / rejected — and *why*).

---

## Template

### YYYY-MM-DD — short title

**Asked:** ...

**Got:** ...

**Used:** accepted / revised / rejected

**Why:** ...

---

## Entries

### 2026-05-06 — Implement non-§7 modules

**Asked:** Fill in `workspace.cpp`, `ui.cpp`, and `plot.cpp` — but not the parts I claimed for myself in design_doc.md §7 (ComplexNumber method bodies, main menu loop, viewport math).

**Got:**
- `workspace.cpp` — full save/load/log with malformed-line counting, missing-file tolerance, ISO-timestamped log entries.
- `ui.cpp` — ncurses input loop (echo on/off dance), main menu, operation menu, number prompt, operand picker, double/name validation with re-prompt loops.
- `plot.cpp` — Bresenham line, parametric circle, parallelogram, rotation arc, plot view loop with pan/zoom/sum/product toggles. `worldToScreen` and `autoFitViewport` left as TODO stubs as agreed.

Builds clean with `-Wall -Wextra`, zero warnings.

**Used:** accepted as a starting point; I will do my own pass to (a) implement the §7 stubs, (b) review the ncurses input flow for edge cases, and (c) decide whether the parallelogram/rotation glyphs are readable in practice.

**Why:** The boundary held — nothing the design doc reserved for me got auto-written. The ncurses + algorithms parts are exactly the kind of fiddly boilerplate I flagged for AI help in §6, so accepting those is consistent with the plan.

---

### 2026-05-06 — PRD interview + project scaffolding

**Asked:** Read existing `complexComparison.cpp` and the project brief; interview me on direction; draft a design doc; scaffold the project structure.

**Got:** A multi-question interview that locked in scope (visualizer focus, badge track, custom class, ncurses, save+log persistence). Then a full `design_doc.md` matching the template plus badge-track sections (requirements analysis, OO design, test plan). Then `src/` skeleton with headers, stubbed `.cpp` files, Makefile, README, and these log files.

**Used:** accepted with carve-outs.

**Why:** I told the assistant up front that the `ComplexNumber` class implementation, the main menu loop, and the viewport math are mine to write — see design_doc.md §7. The scaffolding respects that: those files are stubs with TODOs, not pre-written implementations.
