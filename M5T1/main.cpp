
/*
CSC 134
M5T1 - More functions
kuttlerj6796
3/18/26
*/


#include <iostream>
using namespace std;
// show off different function types
//function declarations
void say_hi();
int show_answer();
double square_a_number(double number);
//Main() goes here
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

void say_hi(){
            cout << "Hello world!";
}

int show_answer(){
    int answer = 42;
    return answer;
}
double square_a_number(double number){
    double square = number * number;
    return square;
}
