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
        games_played++;
        hp = 100;
        has_translator = false;
        turns = 0;

        cout << "\n--- ALIEN SHED: SURVIVAL (Game #" << games_played << ") ---" << endl;
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

        if (turns > high_score) {
            high_score = turns;
            cout << "NEW PERSONAL BEST!" << endl;
        }

        cout << "\nPlay again? (y/n): ";
        cin >> play_again;

    } while (play_again == 'y' || play_again == 'Y');

    // --- FINAL SESSION STATS & RANKING ---
    string rank;
    if (high_score >= 50) rank = "Galactic Legend";
    else if (high_score >= 30) rank = "Veteran Explorer";
    else if (high_score >= 15) rank = "Lucky Survivor";
    else rank = "Space Dust";

    cout << "\n================================" << endl;
    cout << "       FINAL SESSION STATS      " << endl;
    cout << "================================" << endl;
    cout << "Total Games Played: " << games_played << endl;
    cout << "Best Turn Count:    " << high_score << endl;
    cout << "Final Rank:         " << rank << endl;
    cout << "================================" << endl;
    cout << "Thanks for playing! Press Enter to exit." << endl;

    return 0;
}