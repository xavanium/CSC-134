#include "ComplexNumber.h"

#include <cmath>
#include <sstream>
#include <stdexcept>

ComplexNumber::ComplexNumber(std::string name, double real, double imag)
    : name_(std::move(name)), real_(real), imag_(imag) {}

double ComplexNumber::magnitude() const {
    return std::hypot(real_, imag_);
}

double ComplexNumber::argument() const {
    return std::atan2(imag_, real_);
}

ComplexNumber ComplexNumber::conjugate() const {
    return ComplexNumber("", real_, -imag_);
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    return ComplexNumber("", real_ + other.real_, imag_ + other.imag_);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
    return ComplexNumber("", real_ - other.real_, imag_ - other.imag_);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
    return ComplexNumber("",
                        real_ * other.real_ - imag_ * other.imag_,
                        real_ * other.imag_ + imag_ * other.real_);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const {
    constexpr double kEpsilon = 1e-12;
    if (other.magnitude() < kEpsilon) {
        throw std::domain_error("division by zero complex number");
    }
    const double denom = other.real_ * other.real_ + other.imag_ * other.imag_;
    const double r = (real_ * other.real_ + imag_ * other.imag_) / denom;
    const double i = (imag_ * other.real_ - real_ * other.imag_) / denom;
    return ComplexNumber("", r, i);
}

std::string ComplexNumber::toString() const {
    std::ostringstream oss;
    if (!name_.empty()) oss << name_ << " = ";
    oss << real_;
    if (imag_ >= 0.0) oss << " + " << imag_ << "i";
    else              oss << " - " << -imag_ << "i";
    return oss.str();
}
