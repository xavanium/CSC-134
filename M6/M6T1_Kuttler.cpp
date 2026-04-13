/* CSC 134
M6T1 - Arrays (XP Tracker)
Kuttlerj6796
4/13/26
gather XP per floor, then do stats. */

void barChart(int xp[], int floors);

#include <iostream>
using namespace std;  
int main(){
    const int SIZE = 5; //can only be changed at compile time
    int xp[SIZE];
    int max = 0;
    double total = 0.0;
    double average;
    cout << "Dungeon XP Tracker" << endl;
    for (int i = 0; i<SIZE; i++){
        cout << "Floor " << i+1 << " XP: ";
        cin >> xp[i];
        if (xp[i] > max) {
            max = xp[i];
        }
    }
    for (int i = 0; i<SIZE; i++) {
        total += xp[i];
    }
    average = total / SIZE;
    cout << "Over " << SIZE << " floors" << endl;
    cout << "Total XP: " << total << endl;
    cout << "Avg XP: " << average << endl;
    cout << "Best XP: " << max << endl;
    barChart(xp, SIZE);
    return 0;
}

void barChart(int xp[], int floors){
    const int SCALE = 10;
    for (int i = 0; i < floors; i++){
        cout << "F" << (i+1) << " | ";
        for (int b = 0; b<xp[i]/SCALE; b++){
            cout << "🦛 ";
        }
        cout << " " << xp[i] << endl;
    }
}