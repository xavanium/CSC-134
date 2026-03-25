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
    if (has_translator) {
        if (hp == 100) {
            cout << "\n!!! SECRET ENDING UNLOCKED !!!" << endl;
            cout << "The wall glows gold. A hidden compartment opens..." << endl;
            cout << "You find a ticket for a luxury space cruiser. You're going home in style!" << endl;
            turns += 50; // Huge score boost for the secret ending
        } else {
            cout << "\nThe wall says: 'Earth is a 1-star resort.' Ouch." << endl;
        }
    } else {
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
    cout << "1. Fight back\n2. Try to talk\n> ";
    
    if (get_valid_input() == 1) {
        alien_boss_fight();
    } else {
        // New Sneak/Talk Logic
        int sneak_chance = rand() % 100;

        if (sneak_chance < 15) { // 15% chance to be a ninja
            cout << "The alien is confused by your peaceful gestures! It lets you pass." << endl;
            cout << "You grab the bag while its back is turned. NO DAMAGE!" << endl;
            shed_search();
        } else {
            cout << "It doesn't want to talk. It punts you across the room!" << endl;
            hp -= 30;
            check_status();
            if (hp > 0) shed_search();
        }
    }
}

inline void walk_inside() {
    cout << "\nYou enter. A vial of 'Glowing Goop' sits on a rusty table." << endl;
    cout << "1. Drink it\n2. Ignore it\n> ";
    
    if (get_valid_input() == 1) {
        int risk = rand() % 100; // Roll 0-99

        if (risk < 5) { // 5% chance: Instant Death
            cout << "CRITICAL FAILURE! Your body dissolves into space-dust." << endl;
            hp = 0;
        } 
        else if (risk < 15) { // 10% chance (5 to 14): Super Soldier Buff
            cout << "MIRACLE! The goop heals you and makes your muscles bulge!" << endl;
            hp = 100; 
            cout << "You feel unstoppable! (HP Restored to 100)" << endl;
        } 
        else { // 85% chance: Standard Damage
            cout << "It tastes like battery acid and regret! You lose 40 HP." << endl;
            hp -= 40;
        }
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