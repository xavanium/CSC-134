/* CSC 134
M6T1 - Arrays (XP Tracker)
Kuttlerj6796
4/13/26 */
//gather XP per floor, then do stats.

#include <iostream>
using namespace std;  
int main(){
    const int SIZE = 5; //can only be changed at compile time
    int xp[SIZE];
    double total = 0.0;
    double average;
    cout << "Dungeon XP Tracker" << endl;
    for (int i = 0; i<SIZE; i++){
        cout << "Floor " << i+1 << " XP: ";
        cin >> xp[i];
    }
    return 0;
}