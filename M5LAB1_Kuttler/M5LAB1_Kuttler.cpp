#include <iostream>
#include <cstdlib>
#include <ctime>
#include "M5LAB1.h"

using namespace std;

// Define the globals here
bool has_translator = false;
// --- GLOBAL DEFINITIONS ---
int high_score = 0; // Tracks the best 'turns survived' across games

int main() {
    srand(time(0));
    char play_again;

    do {
        // Reset for new game
        hp = 100;
        has_translator = false;
        turns = 0;

        cout << "--- ALIEN SHED: SURVIVAL ---" << endl;
        cout << "Current High Score: " << high_score << " turns" << endl;
        cout << "----------------------------" << endl;
        cout << "1. Enter the shed\n2. Walk past it\n> ";

        int choice = get_valid_input();

        if (choice == 1) walk_inside();
        else walk_past();

        // End of Game Logic
        if (hp <= 0) {
            cout << "\n[GAME OVER] Score: " << turns << " turns." << endl;
        } else {
            cout << "\n*** YOU SURVIVED! ***" << endl;
            cout << "Final HP: " << hp << " | Total Turns: " << turns << endl;
        }

        // Update High Score if this run was better
        if (turns > high_score) {
            cout << "NEW HIGH SCORE!" << endl;
            high_score = turns;
        }

        cout << "\nPlay again? (y/n): ";
        cin >> play_again;
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}