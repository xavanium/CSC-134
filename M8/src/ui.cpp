#include "ui.h"

// Stubs. Menu/state flow is user-owned per §7; ncurses input boilerplate
// is fair game for AI assistance per §6.

namespace ui {

MainChoice displayMainMenu() {
    // TODO
    return MainChoice::QuitWithoutSaving;
}

Op pickOperation() {
    // TODO
    return Op::Compare;
}

ComplexNumber promptForNumber(const std::vector<ComplexNumber>& /*existing*/) {
    // TODO
    return ComplexNumber("", 0.0, 0.0);
}

std::optional<std::size_t> pickOperand(const std::string& /*prompt*/,
                                       const std::vector<ComplexNumber>& /*numbers*/) {
    // TODO
    return std::nullopt;
}

double validateDouble(const std::string& /*prompt*/) {
    // TODO: ncurses input loop; reject non-numeric via std::stod + try/catch.
    return 0.0;
}

std::string validateName(const std::string& /*prompt*/,
                         const std::vector<ComplexNumber>& /*existing*/) {
    // TODO: reject empty; reject duplicates of existing names.
    return "";
}

void showMessage(const std::string& /*msg*/) {
    // TODO: status bar / modal.
}

void showError(const std::string& /*msg*/) {
    // TODO
}

}  // namespace ui
