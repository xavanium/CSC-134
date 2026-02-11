/* */
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    cout << "Question 1: \n" << endl;
    //question 1 code here
    int actNum;
    string name, action;
    double startBal, deposit = 0, withdrawal = 0, endBal;
    cout << "Welcome to the ATM.\n" << "Please, enter your account name: ";
    getline(cin, name);
    cout << "Enter your account number: ";
    cin >> actNum;
    cout << "Input your starting balance: ";
    cin >> startBal;
    cout << endl;
    cout << "Would you like to deposit or withdrawal? \n";
    cin >> action;
    if (action=="deposit") {
        cout << "Input the amount you would like to deposit: ";
        cin >> deposit;
        endBal = startBal + deposit;
    }
    else if (action=="withdrawal"){
        cout << "Input the amount you would like to withdrawal: ";
        cin >> withdrawal;
        endBal = startBal - withdrawal;
    }
    cout << "Account name: " << name << endl;
    cout << "Account number: " << actNum << endl;
    cout << fixed << setprecision(2);
    cout << "Amount of deposit: $" << deposit << endl;
    cout << "Amount of withdrawal: $" << withdrawal << endl;
    cout << "Final balance: $" << endBal << endl;



    cout << "Question 2: " << endl;
    //question 2 code here
    cout << "Question 3: " << endl;
    //question 3 code here
    return 0;
}