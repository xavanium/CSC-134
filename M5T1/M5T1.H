#ifndef M5T1_H_INCLUDED
#define M5T1_H_INCLUDED


/*
CSC 134
M5T1 - More functions
kuttlerj6796
3/18/26
*/


#include <iostream>
using namespace std;
#include "M5T1.H"
int main()
{
    say_hi();
    cout << "The answer is: " << show_answer() << endl;
    cout << "Enter a number: ";
    double number;
    cin >> number;
    double answer = square_a_number(number);
    cout << number << " squared is " << answer << endl;
    return 0;
}


#endif // M5T1_H_INCLUDED
