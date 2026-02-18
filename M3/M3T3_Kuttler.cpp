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
    cout << roll() << endl;

    return 0;
}

int roll(){
    int num = rand() % 6 + 1;
    return num; 
}