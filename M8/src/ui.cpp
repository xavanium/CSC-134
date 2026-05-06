#include "ui.h"

#include <ncurses.h>

#include <cstring>
#include <stdexcept>
#include <string>

namespace ui {

namespace {

// Single-line text prompt at row (h-3). Returns what the user typed.
std::string promptString(const std::string& prompt) {
    int h, w;
    getmaxyx(stdscr, h, w);
    (void)w;

    const int row = h - 3;
    move(row, 0);
    clrtoeol();
    addstr(prompt.c_str());
    refresh();

    char buf[256];
    std::memset(buf, 0, sizeof(buf));
    echo();
    curs_set(1);
    getnstr(buf, sizeof(buf) - 1);
    curs_set(0);
    noecho();

    move(row, 0);
    clrtoeol();
    refresh();
    return std::string(buf);
}

}  // namespace

MainChoice displayMainMenu() {
    clear();
    int row = 1;
    mvaddstr(row++, 2, "ComplexLab — Main Menu");
    mvaddstr(row++, 2, "----------------------");
    ++row;
    mvaddstr(row++, 4, "[1] Add number");
    mvaddstr(row++, 4, "[2] List saved");
    mvaddstr(row++, 4, "[3] Run operation");
    mvaddstr(row++, 4, "[4] Plot");
    mvaddstr(row++, 4, "[5] View history");
    mvaddstr(row++, 4, "[6] Save & quit");
    mvaddstr(row++, 4, "[7] Quit without saving");
    ++row;
    mvaddstr(row, 2, "Choice: ");
    refresh();

    while (true) {
        const int c = getch();
        switch (c) {
            case '1': return MainChoice::AddNumber;
            case '2': return MainChoice::ListSaved;
            case '3': return MainChoice::RunOperation;
            case '4': return MainChoice::Plot;
            case '5': return MainChoice::ViewHistory;
            case '6': return MainChoice::SaveAndQuit;
            case '7': return MainChoice::QuitWithoutSaving;
            default: break;  // ignore other keys
        }
    }
}

Op pickOperation() {
    clear();
    int row = 1;
    mvaddstr(row++, 2, "Pick an operation");
    mvaddstr(row++, 2, "-----------------");
    ++row;
    mvaddstr(row++, 4, "[a] Add        (z1 + z2)");
    mvaddstr(row++, 4, "[s] Subtract   (z1 - z2)");
    mvaddstr(row++, 4, "[m] Multiply   (z1 * z2)");
    mvaddstr(row++, 4, "[d] Divide     (z1 / z2)");
    mvaddstr(row++, 4, "[c] Compare    magnitudes of z1, z2");
    mvaddstr(row++, 4, "[j] Conjugate  (z̄)");
    refresh();

    while (true) {
        const int c = getch();
        switch (c) {
            case 'a': case 'A': return Op::Add;
            case 's': case 'S': return Op::Sub;
            case 'm': case 'M': return Op::Mul;
            case 'd': case 'D': return Op::Div;
            case 'c': case 'C': return Op::Compare;
            case 'j': case 'J': return Op::Conjugate;
            default: break;
        }
    }
}

ComplexNumber promptForNumber(const std::vector<ComplexNumber>& existing) {
    clear();
    mvaddstr(1, 2, "Add a complex number");
    mvaddstr(2, 2, "--------------------");
    refresh();

    std::string name = validateName("  Name (e.g. z1): ", existing);
    const double r = validateDouble("  Real part: ");
    const double i = validateDouble("  Imaginary part: ");
    return ComplexNumber(std::move(name), r, i);
}

std::optional<std::size_t> pickOperand(const std::string& prompt,
                                       const std::vector<ComplexNumber>& numbers) {
    if (numbers.empty()) {
        showError("No numbers in workspace yet — add one first.");
        return std::nullopt;
    }

    clear();
    int row = 1;
    mvaddstr(row++, 2, prompt.c_str());
    mvaddstr(row++, 2, std::string(prompt.size(), '-').c_str());
    ++row;
    for (std::size_t i = 0; i < numbers.size() && i < 9; ++i) {
        const std::string label =
            "[" + std::to_string(i + 1) + "] " + numbers[i].toString();
        mvaddstr(row++, 4, label.c_str());
    }
    if (numbers.size() > 9) {
        mvaddstr(row++, 4, "(only the first 9 are selectable from this menu)");
    }
    ++row;
    mvaddstr(row, 2, "Choice (q to cancel): ");
    refresh();

    while (true) {
        const int c = getch();
        if (c == 'q' || c == 'Q' || c == 27) return std::nullopt;
        if (c >= '1' && c <= '9') {
            const std::size_t idx = static_cast<std::size_t>(c - '1');
            if (idx < numbers.size()) return idx;
        }
    }
}

double validateDouble(const std::string& prompt) {
    while (true) {
        const std::string s = promptString(prompt);
        try {
            std::size_t consumed = 0;
            const double v = std::stod(s, &consumed);
            // Trailing non-whitespace junk -> treat as bad input.
            for (std::size_t i = consumed; i < s.size(); ++i) {
                if (!std::isspace(static_cast<unsigned char>(s[i]))) {
                    throw std::invalid_argument("trailing");
                }
            }
            return v;
        } catch (...) {
            showError("Not a number — try again.");
        }
    }
}

std::string validateName(const std::string& prompt,
                         const std::vector<ComplexNumber>& existing) {
    while (true) {
        const std::string s = promptString(prompt);
        if (s.empty()) {
            showError("Name cannot be empty.");
            continue;
        }
        if (s.find(',') != std::string::npos) {
            showError("Name cannot contain a comma (file format reserves it).");
            continue;
        }
        bool dup = false;
        for (const auto& n : existing) {
            if (n.name() == s) { dup = true; break; }
        }
        if (dup) {
            showError("Name already in use — choose another.");
            continue;
        }
        return s;
    }
}

void showMessage(const std::string& msg) {
    int h, w;
    getmaxyx(stdscr, h, w);
    (void)w;
    move(h - 1, 0);
    clrtoeol();
    addstr(msg.c_str());
    addstr("   [press any key]");
    refresh();
    getch();
    move(h - 1, 0);
    clrtoeol();
    refresh();
}

void showError(const std::string& msg) {
    showMessage("Error: " + msg);
}

}  // namespace ui
