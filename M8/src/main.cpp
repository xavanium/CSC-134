#include <iostream>
#include <vector>

#include "ComplexNumber.h"
#include "input.h"
#include "plot.h"

int main() {
    std::cout << "ComplexLab - Argand-plane visualizer\n"
              << "Enter complex numbers (real part, then imaginary part).\n"
              << "Type 'q' at the real-part prompt to quit.\n";

    std::vector<ComplexNumber> numbers;
    renderPlot(numbers);

    while (auto z = promptForNumber()) {
        numbers.push_back(*z);
        renderPlot(numbers);
    }

    std::cout << "Goodbye.\n";
    return 0;
}
