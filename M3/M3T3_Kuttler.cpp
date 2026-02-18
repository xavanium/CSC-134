/* M3T3 - Craps & Random Numbers
Kuttlerj6796
CSC 134
2/18/26
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//function prototype - declare whats coming

int roll(); //returns number from 1-6

int main(){
    //seed the RNG
    int roll1, roll2, total, point;
    string status; // win, lose
    srand(time(0));
    roll1 = roll();
    roll2 = roll();
    total = roll1 + roll2;

    //print roll
    cout << "Roll is: 🎲 " << roll1 << " + " << roll2 << " = " << total << endl;
    // determine win or loss
    if (total == 7 || total == 11){ // || is OR
        status = "win";
    } else if (total == 2 || total == 3 || total == 12) {
        status = "loss";
    }
    else {
        //point
        point = total; //save for later
        status = "point";
    }
    cout << "Roll results: " << status << endl;
    return 0; 
}

int roll(){
    int num = rand() % 6 + 1;
    return num; 
}