// ComplexLab — composition root.

#include <ncurses.h>

#include <stdexcept>
#include <string>
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

void showLines(const std::string& title, const std::vector<std::string>& lines) {
    int h, w;
    getmaxyx(stdscr, h, w);
    (void)w;

    clear();
    int row = 1;
    mvaddstr(row++, 2, title.c_str());
    mvaddstr(row++, 2, std::string(title.size(), '-').c_str());
    ++row;

    if (lines.empty()) {
        mvaddstr(row++, 4, "(none)");
    } else {
        const std::size_t maxRows = (h > 6) ? static_cast<std::size_t>(h - 6) : 1;
        const std::size_t start = (lines.size() > maxRows) ? lines.size() - maxRows : 0;
        for (std::size_t i = start; i < lines.size() && row < h - 2; ++i) {
            mvaddstr(row++, 4, lines[i].c_str());
        }
    }

    mvaddstr(h - 1, 2, "[press any key]");
    refresh();
    getch();
}

const char* opLabel(ui::Op op) {
    switch (op) {
        case ui::Op::Add:       return "+";
        case ui::Op::Sub:       return "-";
        case ui::Op::Mul:       return "*";
        case ui::Op::Div:       return "/";
        case ui::Op::Compare:   return "cmp";
        case ui::Op::Conjugate: return "conj";
    }
    return "?";
}

void runOperation(std::vector<ComplexNumber>& numbers) {
    const ui::Op op = ui::pickOperation();

    auto i1 = ui::pickOperand("Pick first operand", numbers);
    if (!i1) return;
    const ComplexNumber& a = numbers[*i1];

    if (op == ui::Op::Conjugate) {
        const ComplexNumber result = a.conjugate();
        const std::string entry = "conj(" + a.name() + ") = " + result.toString();
        ui::showMessage(entry);
        workspace::appendLog(kLogPath, entry);
        return;
    }

    auto i2 = ui::pickOperand("Pick second operand", numbers);
    if (!i2) return;
    const ComplexNumber& b = numbers[*i2];

    if (op == ui::Op::Compare) {
        const double ma = a.magnitude();
        const double mb = b.magnitude();
        std::string verdict;
        if (ma > mb)      verdict = "|" + a.name() + "| > |" + b.name() + "|";
        else if (mb > ma) verdict = "|" + a.name() + "| < |" + b.name() + "|";
        else              verdict = "|" + a.name() + "| == |" + b.name() + "|";
        ui::showMessage(verdict);
        workspace::appendLog(kLogPath, verdict);
        return;
    }

    try {
        ComplexNumber result("", 0.0, 0.0);
        switch (op) {
            case ui::Op::Add: result = a + b; break;
            case ui::Op::Sub: result = a - b; break;
            case ui::Op::Mul: result = a * b; break;
            case ui::Op::Div: result = a / b; break;
            default: return;
        }
        const std::string entry =
            a.name() + " " + opLabel(op) + " " + b.name() + " = " + result.toString();
        ui::showMessage(entry);
        workspace::appendLog(kLogPath, entry);
    } catch (const std::domain_error& e) {
        ui::showError(e.what());
    }
}

}  // namespace

int main() {
    initCurses();

    auto loaded = workspace::load(kWorkspacePath);
    std::vector<ComplexNumber> numbers = std::move(loaded.numbers);
    if (loaded.skippedLines > 0) {
        ui::showMessage("Workspace had " + std::to_string(loaded.skippedLines) +
                        " malformed line(s) — skipped.");
    }

    bool saveOnExit = false;
    bool quit = false;

    while (!quit) {
        switch (ui::displayMainMenu()) {
            case ui::MainChoice::AddNumber: {
                ComplexNumber z = ui::promptForNumber(numbers);
                const std::string entry = "added " + z.toString();
                numbers.push_back(std::move(z));
                workspace::appendLog(kLogPath, entry);
                break;
            }
            case ui::MainChoice::ListSaved: {
                std::vector<std::string> lines;
                lines.reserve(numbers.size());
                for (const auto& n : numbers) lines.push_back(n.toString());
                showLines("Saved numbers", lines);
                break;
            }
            case ui::MainChoice::RunOperation:
                runOperation(numbers);
                break;
            case ui::MainChoice::Plot:
                openPlotView(numbers);
                break;
            case ui::MainChoice::ViewHistory:
                showLines("History", workspace::loadLog(kLogPath));
                break;
            case ui::MainChoice::SaveAndQuit:
                saveOnExit = true;
                quit = true;
                break;
            case ui::MainChoice::QuitWithoutSaving:
                quit = true;
                break;
        }
    }

    if (saveOnExit) {
        workspace::save(kWorkspacePath, numbers);
    }

    shutdownCurses();
    return 0;
}
