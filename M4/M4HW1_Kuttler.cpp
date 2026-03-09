/* M4HW1 - Kuttlerj6796
3/9/26
CSC 134
Gold cuz im a fricken genius and a genetic freak */

#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "Input the integer (1-12) you'd like to make a times table with: ";
    cin >> num;
    while(num<1 || num>12){
        cout << "Try again." << endl;
        cout << "Input an integer from 1-12: ";
        cin >> num;
    }
    for (int i = 1; i<=12; i++){
        cout << num << " times " << i << " is " << num*i << endl; 
    }
    cout << "And now you know the times table of " << num << "!" << endl;
    return 0;
}