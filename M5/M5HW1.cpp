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
    question1();
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