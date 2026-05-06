#pragma once

#include <cstddef>
#include <optional>
#include <string>
#include <vector>

#include "ComplexNumber.h"

namespace ui {

enum class MainChoice {
    AddNumber,
    ListSaved,
    RunOperation,
    Plot,
    ViewHistory,
    SaveAndQuit,
    QuitWithoutSaving,
};

enum class Op { Add, Sub, Mul, Div, Compare, Conjugate };

MainChoice displayMainMenu();
Op pickOperation();

ComplexNumber promptForNumber(const std::vector<ComplexNumber>& existing);

// Returns index into `numbers`, or std::nullopt if user cancels.
std::optional<std::size_t> pickOperand(const std::string& prompt,
                                       const std::vector<ComplexNumber>& numbers);

// Validation helpers.
double validateDouble(const std::string& prompt);
std::string validateName(const std::string& prompt,
                         const std::vector<ComplexNumber>& existing);

// Status / message helpers.
void showMessage(const std::string& msg);
void showError(const std::string& msg);

}  // namespace ui
