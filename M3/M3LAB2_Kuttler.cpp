/*
Kuttlerj6796
CSC 134
M3LAB2
2/25/26
*/

#include <iostream>
using namespace std;
int main(){
    int numGrade;
    char grade;
    cout << "Enter your numerical grade: ";
    cin >> numGrade;
    if (numGrade>=90 && numGrade<=100){
       grade = 'A'; 
    } else if (numGrade>=80 && numGrade<=89){
        grade = 'B';
    } else if (numGrade>=70 && numGrade<=79){
        grade = 'C';
    } else if (numGrade>=60 && numGrade<=69){
        grade = 'D';
    } else {
        grade = 'F';
    }
    cout << "Your grade is " << grade << endl << endl;
    return 0;
}