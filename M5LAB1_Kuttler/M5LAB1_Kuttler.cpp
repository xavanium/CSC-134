/* 
CSC 134
kuttlerj6796
3/25/26
M5LAB1 - M3 game, but cooler
*/

#include <iostream>
#include <ctime>
#include "M5LAB1.h"

using namespace std;

int main() {
    srand(time(0));
    char play_again;

    do {
        hp = 100;
        has_translator = false;
        turns = 0;

        cout << "--- ALIEN SHED: SURVIVAL ---" << endl;
        cout << "Current High Score: " << high_score << " turns" << endl;
        cout << "1. Enter the shed\n2. Walk past it\n> ";

        int choice = get_valid_input();

        if (choice == 1) walk_inside();
        else walk_past();

        if (hp <= 0) {
            cout << "\n[GAME OVER] Score: " << turns << " turns." << endl;
        } else {
            cout << "\n*** YOU SURVIVED! ***\nFinal HP: " << hp << endl;
        }

        if (turns > high_score) high_score = turns;

        cout << "\nPlay again? (y/n): ";
        cin >> play_again;
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}