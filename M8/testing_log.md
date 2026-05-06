# Testing Log — ComplexLab

Test cases driven by `design_doc.md` §11. Mark each row as you go.

Legend: ✅ pass · ❌ fail · ⏳ not yet run · 🔧 fixed bug found here

---

## Unit — ComplexNumber

| Case | Expected | Actual | Status |
|---|---|---|---|
| `ComplexNumber("z", 3, 4).magnitude()` | `5.0` | | ⏳ |
| `(3+4i) + (1-2i)` | `4 + 2i` | | ⏳ |
| `(3+4i) - (1-2i)` | `2 + 6i` | | ⏳ |
| `(3+4i) * (1-2i)` | `11 - 2i` | | ⏳ |
| `(3+4i) / (1-2i)` | `-1 + 2i` | | ⏳ |
| `(3+4i) / (0+0i)` | throws `domain_error` | | ⏳ |
| `(3+4i).conjugate()` | `3 - 4i` | | ⏳ |
| `toString()` of `3 - 4i` | `"3 - 4i"` (sign formatted) | | ⏳ |

## Input validation

| Case | Expected | Status |
|---|---|---|
| Type letters when number expected | re-prompt, no crash | ⏳ |
| Empty name | re-prompt | ⏳ |
| Duplicate name | re-prompt | ⏳ |
| Magnitude of `1e100 + 1e100i` | no overflow (hypot is safe) | ⏳ |

## Persistence

| Case | Expected | Status |
|---|---|---|
| Fresh run, no workspace file | empty workspace, no error | ⏳ |
| Save 3 numbers, quit, relaunch | all 3 reappear | ⏳ |
| Manually corrupt one workspace line | other lines load, warning shown | ⏳ |
| Operation log persists across sessions | append, not overwrite | ⏳ |

## Plot

| Case | Expected | Status |
|---|---|---|
| Plot single number at origin | no crash, no div-by-zero in viewport | ⏳ |
| Plot tiny + huge magnitudes together | autofit picks larger, tiny near origin | ⏳ |
| Resize terminal mid-plot | redraw or "too small" message | ⏳ |
| Sum overlay on z1, z2 | parallelogram corners at 0, z1, z1+z2, z2 | ⏳ |
| Product overlay on z1, z2 | rotation arc visible | ⏳ |

## Build

| Case | Expected | Status |
|---|---|---|
| `make` clean build | zero warnings | ⏳ |
| `make clean && make` from scratch | succeeds | ⏳ |

---

## Bugs found and fixed

*(record here as you go: symptom, root cause, fix)*
