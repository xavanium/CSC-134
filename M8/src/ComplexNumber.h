#ifndef COMPLEXLAB_COMPLEXNUMBER_H
#define COMPLEXLAB_COMPLEXNUMBER_H

#include <string>

class ComplexNumber {
public:
    ComplexNumber(double real, double imag);

    double real() const;
    double imag() const;
    double magnitude() const;
    double argument() const;

    std::string toString() const;

private:
    double real_;
    double imag_;
};

#endif
