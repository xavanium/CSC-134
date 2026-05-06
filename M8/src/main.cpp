// ComplexLab — composition root.
// Per design_doc.md §7, the menu loop and state management are user-owned.
// The skeleton below shows the intended startup/shutdown structure;
// replace TODOs with the real flow.

#include <ncurses.h>

#include <vector>

#include "ComplexNumber.h"
#include "plot.h"
#include "ui.h"
#include "workspace.h"

namespace {

constexpr const char* kWorkspacePath = "complexlab_workspace.txt";
constexpr const char* kLogPath = "complexlab_history.log";

void initCurses() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

void shutdownCurses() {
    endwin();
}

}  // namespace

int main() {
    initCurses();

    auto loaded = workspace::load(kWorkspacePath);
    std::vector<ComplexNumber> numbers = std::move(loaded.numbers);
    // TODO: if loaded.skippedLines > 0, surface a warning via ui::showMessage.

    bool saveOnExit = false;

    // TODO: main menu loop.
    // while (true) {
    //     switch (ui::displayMainMenu()) {
    //         case ui::MainChoice::AddNumber:        ...
    //         case ui::MainChoice::ListSaved:        ...
    //         case ui::MainChoice::RunOperation:     ...
    //         case ui::MainChoice::Plot:             openPlotView(...); break;
    //         case ui::MainChoice::ViewHistory:      ...
    //         case ui::MainChoice::SaveAndQuit:      saveOnExit = true; goto done;
    //         case ui::MainChoice::QuitWithoutSaving: goto done;
    //     }
    // }

    if (saveOnExit) {
        workspace::save(kWorkspacePath, numbers);
    }

    shutdownCurses();
    return 0;
}
