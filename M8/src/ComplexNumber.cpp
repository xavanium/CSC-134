#include "ComplexNumber.h"

#include <cmath>
#include <sstream>
#include <iomanip>

ComplexNumber::ComplexNumber(double real, double imag)
    : real_(real), imag_(imag) {}

double ComplexNumber::real() const { return real_; }
double ComplexNumber::imag() const { return imag_; }

double ComplexNumber::magnitude() const {
    return std::hypot(real_, imag_);
}

double ComplexNumber::argument() const {
    return std::atan2(imag_, real_);
}

std::string ComplexNumber::toString() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << real_;
    if (imag_ >= 0.0) {
        oss << " + " << std::fixed << std::setprecision(2) << imag_ << "i";
    } else {
        oss << " - " << std::fixed << std::setprecision(2) << -imag_ << "i";
    }
    return oss.str();
}
