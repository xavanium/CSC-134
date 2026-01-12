//CSC 134
// M1T1 (Module 1, Tutorial 1)


//We'll explain this later
#include <iostream>
using namespace std;

int main() {
    // Say hello
    cout << "Hello, World!" << endl;
    cout << endl; //blank line
    cout << "Enter your name: ";
    string name; //declared a string variable
    cin >> name; //get input from user
    cout << "Hello " + name + " welcome to C++!";
    cout << endl;
    return 0; //exit with no errors
}
