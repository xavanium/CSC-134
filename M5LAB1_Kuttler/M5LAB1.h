#ifndef M5LAB1_H_INCLUDED
#define M5LAB1_H_INCLUDED

#include <iostream>
#include <cstdlib>

using namespace std;

// --- GLOBALS ---
inline bool has_translator = false;
inline int hp = 100;
inline int turns = 0;
inline int high_score = 0;
inline int games_played = 0; // <--- Add this line

// --- FUNCTIONS ---

inline int get_valid_input() {
    turns++;
    int input;
    while (!(cin >> input)) {
        cout << "Numbers only: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    return input;
}

inline void check_status() {
    if (hp <= 0) {
        hp = 0;
        cout << "\n--- DEATH HAS ARRIVED ---" << endl;
    } else {
        cout << "[HP: " << hp << " | Turn: " << turns << "]" << endl;
    }
}

inline void decode_cover() {
    if (has_translator) cout << "\nWall: 'Earth is a 1-star resort.'" << endl;
    else {
        hp -= 10;
        cout << "Confusing symbols hurt your brain. -10 HP." << endl;
        check_status();
    }
}

inline void shed_search() {
    cout << "\nYou find a translator!" << endl;
    has_translator = true;
    cout << "1. Decode walls\n2. Run\n> ";
    if (get_valid_input() == 1) decode_cover();
}

inline void alien_boss_fight() {
    int alien_hp = 100;
    while (alien_hp > 0 && hp > 0) {
        cout << "\nAlien: " << alien_hp << " | You: " << hp << endl;
        cout << "1. Heavy Punch\n2. Dodge\n> ";
        int move = get_valid_input();
        if (move == 1) {
            if ((rand() % 100) < 85) {
                int dmg = rand() % 15 + 10;
                if ((rand() % 100) < 15) { dmg *= 2; cout << "CRIT! "; }
                cout << "You hit for " << dmg << "!" << endl;
                alien_hp -= dmg;
            } else cout << "You missed!" << endl;
        }
        if (alien_hp > 0) {
            int a_dmg = (alien_hp < 40) ? (rand() % 25 + 10) : (rand() % 15 + 5);
            if (move == 2) a_dmg /= 3;
            hp -= a_dmg;
            cout << "Alien hits for " << a_dmg << "!" << endl;
            if (hp <= 0) check_status();
        }
    }
}

inline void leave_potion() {
    cout << "\nA giant alien blocks the exit!" << endl;
    cout << "1. Fight\n2. Talk\n> ";
    if (get_valid_input() == 1) alien_boss_fight();
    else {
        cout << "He doesn't wanna talk.\nHe punts you! -60 HP." << endl;
        hp -= 60;
        check_status();
        if (hp > 0) shed_search();
    }
}

inline void walk_inside() {
    cout << "\nYou enter.\nYou see a bottle of glowing goop on a table.\nDrink it?" << endl;
    cout << "1. Drink\n2. Ignore\n> ";
    if (get_valid_input() == 1) {
        hp -= 40;
        cout << "Yuck! It tastes like battery acid! -40 HP." << endl;
        check_status();
    }
    if (hp > 0) leave_potion();
}

inline void walk_past() {
    int choice;
    do {
        cout << "\nAsteroids hit you! You take damage." << endl;
        hp -= (rand() % 15 + 5);
        check_status();
        if (hp <= 0) return;
        cout << "C'mon... you know you wanna go inside...\n1. Go in\n2. No\n> ";
        choice = get_valid_input();
        if (choice == 1) { walk_inside(); return; }
    } while (hp > 0);
}

#endif