/* CSC 134
Kuttlerj6796
M5HW1 - Gold cuz im a fricken genius and genetic freak
4/1/26 */
#include <iostream>
#include <iomanip>
using namespace std;
void question1();
void question2();
void question3();
void question4();
void question5();

int main(){
    question3();
    return 0;
}

void question1(){
    string m1, m2, m3;
    int rf1, rf2, rf3;
    double avg = (rf1+rf2+rf3) / 3.0;
    cout << setprecision(2) << fixed;
    cout << "Enter the first month: ";
    cin >> m1;
    cout << "Enter the average rainfall for " << m1 << ": ";
    cin >> rf1;
    cout << "Enter the second month: ";
    cin >> m2;
    cout << "Enter the average rainfall for " << m2 << ": ";
    cin >> rf2;
    cout << "Enter the third month: ";
    cin >> m3;
    cout << "Enter the average rainfall for " << m3 << ": ";
    cin >> rf3;
    cout << "The average rainfall for " << m1 << ", " << m2 << " and " << m3 << " is " << avg;
    cout << endl;
}

void question2(){
    double height, width, length, area;
    cout << setprecision(2) << fixed;
    cout << "Input the height: ";
    cin >> height;
    cout << "Input the width: ";
    cin >> width;
    cout << "Input the length: ";
    cin >> length;
    area = height*width*length;
    cout << "The area is " << area << endl;
}

void question3(){
    int num;
    string roman;
    cout << "Enter a number (1-10): ";
    cin >> num;
        while (num < 1 || num > 10){
            cout << "Invalid number. Try again: ";
            cin >> num;
    }
    switch (num){ 
        case 1:
            roman = "I";
            break;
        case 2:
            roman = "II";
            break;
        case 3:
            roman = "III";
            break;
        case 4:
            roman = "IV";
            break;
        case 5:
            roman = "V";
            break;
        case 6:
            roman = "VI";
            break;
        case 7:
            roman = "VII";
            break;
        case 8:
            roman = "VIII";
            break;
        case 9:
            roman = "IX";
            break;
        case 10:
            roman = "X";
            break;
    }
    cout << "The roman numeral version of " << num << " is " << roman << endl;
}