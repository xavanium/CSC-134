#include "input.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

namespace {

std::string trim(std::string s) {
    auto notSpace = [](unsigned char c) { return !std::isspace(c); };
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), notSpace));
    s.erase(std::find_if(s.rbegin(), s.rend(), notSpace).base(), s.end());
    return s;
}

bool tryParseDouble(const std::string& s, double& out) {
    if (s.empty()) return false;
    std::istringstream iss(s);
    double d;
    if (!(iss >> d)) return false;
    char extra;
    if (iss >> extra) return false;
    if (!std::isfinite(d)) return false;
    out = d;
    return true;
}

double readDouble(const std::string& prompt) {
    std::string line;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, line)) {
            std::cin.clear();
            return 0.0;
        }
        double d;
        if (tryParseDouble(trim(line), d)) return d;
        std::cout << "  Please enter a finite number.\n";
    }
}

}  // namespace

std::optional<ComplexNumber> promptForNumber() {
    std::string line;
    while (true) {
        std::cout << "Real part (or 'q' to quit): ";
        if (!std::getline(std::cin, line)) {
            std::cin.clear();
            return std::nullopt;
        }
        std::string t = trim(line);
        if (t == "q" || t == "Q") return std::nullopt;

        double r;
        if (tryParseDouble(t, r)) {
            double i = readDouble("Imaginary part: ");
            return ComplexNumber(r, i);
        }
        std::cout << "  Please enter a finite number, or 'q' to quit.\n";
    }
}
