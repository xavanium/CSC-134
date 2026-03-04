/*
CSC 134
M4T1 - While loops
Kuttlerj6796
3/4/26
*/


#include <iostream>
using namespace std;

int main(){
    //DEMO - List of numbers and squares
    const int MIN = 1;
    const int MAX = 10;
    int num = MIN;
    int squared; // holds the square
    cout << "Number\tNum Squared" << endl;
    cout << "___________________" << endl;
    while (num <= MAX){
        squared = num*num;
        cout << num << "\t" << squared << endl;
        num++; // next number
    }

    return 0;
}