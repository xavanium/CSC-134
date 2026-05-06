#pragma once

#include <string>

class ComplexNumber {
public:
    ComplexNumber(std::string name, double real, double imag);

    const std::string& name() const { return name_; }
    double real() const { return real_; }
    double imag() const { return imag_; }

    void rename(std::string newName) { name_ = std::move(newName); }

    double magnitude() const;
    double argument() const;
    ComplexNumber conjugate() const;

    // Arithmetic operators return un-named results (name == "").
    // Caller assigns a name via rename() before adding to a workspace.
    ComplexNumber operator+(const ComplexNumber& other) const;
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(const ComplexNumber& other) const;
    ComplexNumber operator/(const ComplexNumber& other) const;

    std::string toString() const;

private:
    std::string name_;
    double real_;
    double imag_;
};
