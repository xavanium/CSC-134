# ComplexLab

An ncurses Argand-diagram workspace. Build, save, and visualize complex numbers on the complex plane, with geometric visualizations of magnitude, addition, multiplication, and conjugation.

**Track:** A (Badge track)
**Course:** CSC 134 — Project 4

## Build

Requires `g++` with C++17 and the `ncurses` development headers.

```bash
sudo apt-get install -y libncurses-dev   # one-time, on Debian/Ubuntu/Codespaces
make
```

## Run

```bash
./complexlab
```

Workspace persists to `complexlab_workspace.txt`; operation history to `complexlab_history.log`. Both are created in the current working directory on first save.

## Files

```
M8/
├── design_doc.md          ← Design + requirements + test plan
├── src/                   ← Source
│   ├── ComplexNumber.h/.cpp
│   ├── plot.h/.cpp
│   ├── workspace.h/.cpp
│   ├── ui.h/.cpp
│   └── main.cpp
├── Makefile
├── ai_log.md              ← AI interaction log
├── testing_log.md         ← Test cases + results
└── README.md
```

## What I'm most proud of / what I'd improve

*(filled in at end of project)*
