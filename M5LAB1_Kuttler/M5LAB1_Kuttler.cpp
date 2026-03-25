#include <iostream>
#include <cstdlib>
#include <ctime>
#include "M5LAB1.h"

using namespace std;

// Define the globals here
bool has_translator = false;
int hp = 100;

int main() {
    srand(time(0));
    char play_again;

    do {
        hp = 100;
        has_translator = false;

        cout << "--- ALIEN SHED: SURVIVAL ---" << endl;
        cout << "HP: " << hp << " | You see the shed ahead." << endl;
        cout << "1. Enter the shed\n2. Walk past it\n> ";

        int choice = get_valid_input();

        if (choice == 1) walk_inside();
        else walk_past();

        if (hp <= 0) cout << "\n*** YOUR JOURNEY ENDS HERE ***" << endl;
        else cout << "\n*** YOU SURVIVED! ***" << endl;

        cout << "Play again? (y/n): ";
        cin >> play_again;
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}