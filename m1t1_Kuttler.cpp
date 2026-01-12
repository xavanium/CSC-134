//CSC 134
// M1T1 (Module 1, Tutorial 1)


//We'll explain this later
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Say hello
    cout << "Hello, World!" << endl;
    cout << endl; //blank line
    
    string name;
    cout << "Input your name: ";
    cin >> name;
    cout << "Hello, " << name << ", welcome to C++!" << endl;
    cout << endl;
    int num;
    cout << "Input a number: ";
    cin >> num;
    int exponent;
    cout << "Input the exponent for this number: ";
    cin >> exponent;
    int result = pow(num, exponent);
    cout << num << " raised to the power of " << exponent << " is " << result << endl;
    cout << endl;
    return 0; //exit with no errors
}