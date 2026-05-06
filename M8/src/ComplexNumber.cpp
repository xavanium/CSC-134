#include "ComplexNumber.h"

#include <stdexcept>

// Per design_doc.md §7, the body of this class is the user's to write
// without AI. Stubs below let the project link; replace each as you go.

ComplexNumber::ComplexNumber(std::string name, double real, double imag)
    : name_(std::move(name)), real_(real), imag_(imag) {}

double ComplexNumber::magnitude() const {
    // TODO: return sqrt(real_^2 + imag_^2). Use std::hypot for safety.
    return 0.0;
}

double ComplexNumber::argument() const {
    // TODO: return atan2(imag_, real_).
    return 0.0;
}

ComplexNumber ComplexNumber::conjugate() const {
    // TODO: return ComplexNumber("", real_, -imag_).
    return ComplexNumber("", 0.0, 0.0);
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& /*other*/) const {
    // TODO
    return ComplexNumber("", 0.0, 0.0);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& /*other*/) const {
    // TODO
    return ComplexNumber("", 0.0, 0.0);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& /*other*/) const {
    // TODO: (a+bi)(c+di) = (ac - bd) + (ad + bc)i
    return ComplexNumber("", 0.0, 0.0);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const {
    // TODO: (a+bi)/(c+di) = ((ac+bd) + (bc-ad)i) / (c^2 + d^2).
    // Throw std::domain_error if other.magnitude() < epsilon.
    if (other.real_ == 0.0 && other.imag_ == 0.0) {
        throw std::domain_error("division by zero complex number");
    }
    return ComplexNumber("", 0.0, 0.0);
}

std::string ComplexNumber::toString() const {
    // TODO: format like "z1 = 3 + 4i" (handle negative imag as "3 - 4i").
    return name_;
}
