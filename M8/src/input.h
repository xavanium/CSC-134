#ifndef COMPLEXLAB_INPUT_H
#define COMPLEXLAB_INPUT_H

#include <optional>

#include "ComplexNumber.h"

// Prompts for real then imaginary part. Returns std::nullopt if the user
// types 'q' (or 'Q', or EOF) at the real-part prompt.
std::optional<ComplexNumber> promptForNumber();

#endif
