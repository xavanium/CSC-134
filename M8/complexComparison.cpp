//calculator to compare the absolute values of complex numbers

#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>
int main() {
    double r1, i1, r2, i2;
    std::cout << "Input the first real number: ";
    std::cin >> r1;
    std::cout << "Input the imaginary coordinate: ";
    std::cin >> i1;
    std::cout << "Input the second real number: ";
    std::cin >> r2;
    std::cout << "Input the second imaginary coordinate: ";
    std::cin >> i2;
    std::complex<double> z(r1, i1); //defines complex number as r1 + i1
    std::complex<double> w(r2, i2);
    double d1 = std::hypot(z.real(), z.imag()); // sqrt(x*x + y*y)
    double d2 = std::hypot(w.real(), w.imag());
    std::cout << "The magnitude of the first complex number (" << r1 << " + " << i1 << "i) is " << d1 << ".\n";
    std::cout << "The magnitude of the second complex number (" << r2 << " + " << i2 << "i) is " << d2 << ".\n";
    if (d1>d2){
        std::cout << "The magnitude of the first complex number is larger.\n";
    } else if (d1<d2){
        std::cout << "The magnitude of the second complex number is larger.\n";
    } else {
        std::cout << "The magnitudes are equal.\n";
    }
    return 0;
}