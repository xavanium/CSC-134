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

### 2026-05-06 — PRD interview + project scaffolding

**Asked:** Read existing `complexComparison.cpp` and the project brief; interview me on direction; draft a design doc; scaffold the project structure.

**Got:** A multi-question interview that locked in scope (visualizer focus, badge track, custom class, ncurses, save+log persistence). Then a full `design_doc.md` matching the template plus badge-track sections (requirements analysis, OO design, test plan). Then `src/` skeleton with headers, stubbed `.cpp` files, Makefile, README, and these log files.

**Used:** accepted with carve-outs.

**Why:** I told the assistant up front that the `ComplexNumber` class implementation, the main menu loop, and the viewport math are mine to write — see design_doc.md §7. The scaffolding respects that: those files are stubs with TODOs, not pre-written implementations.
