#ifndef M5LAB1_H_INCLUDED
#define M5LAB1_H_INCLUDED
#include <fstream>
#include <iostream>
using namespace std;

// --- SHARED GLOBALS ---
extern bool has_translator = false;
extern int hp = 100;
extern int turns = 0;
extern int high_score;

// --- PROTOTYPES ---
void walk_inside();
void walk_past();
void leave_potion();
void shed_search();
void decode_cover();
void alien_boss_fight();
int get_valid_input();
void check_status();

void walk_inside() {
    cout << "\nYou enter. A vial of 'Glowing Goop' sits there." << endl;
    cout << "1. Drink it\n2. Ignore it\n> ";
    if (get_valid_input() == 1) {
        cout << "It tastes like battery acid! You lose 40 HP." << endl;
        hp -= 40;
        check_status();
    }
    
    // Add this check! 
    if (hp > 0) {
        leave_potion();
    }
}

void walk_past() {
    int attempts = 0;
    int choice;

    do {
        cout << "\nAn asteroid fragments nearby!" << endl;
        int damage = rand() % 15 + 5; // Smaller "nagging" damage
        hp -= damage;
        
        cout << "Shrapnel nicks you for " << damage << " damage." << endl;
        check_status();

        if (hp <= 0) return; // Exit if the asteroids actually kill them

        cout << "\nC'mon... you know you wanna see what's inside..." << endl;
        cout << "1. Fine, I'll go in.\n2. No! I'm staying out here!\n> ";
        choice = get_valid_input();

        if (choice == 1) {
            walk_inside();
            return; // Exit walk_past once they enter
        }
        
        attempts++;
        if (attempts > 2) {
            cout << "The cosmic peer pressure is getting intense!" << endl;
        }

    } while (choice != 1 && hp > 0);
}

void leave_potion() {
    cout << "\nYou hear a heavy metallic THUD behind you." << endl;
    cout << "A 7-foot tall grey alien stands in the doorway!" << endl;
    cout << "1. Fight back\n2. Try to talk\n> ";
    if (get_valid_input() == 1) alien_boss_fight();
    else {
        cout << "It doesn't want to talk. It punts you across the room." << endl;
        hp -= 50;
        check_status();
        if (hp > 0) shed_search();
    }
}

void alien_boss_fight() {
    cout << "\n--- !!! BOSS FIGHT: THE ADJUDICATOR !!! ---" << endl;
    int alien_hp = 100; 
    
    while (alien_hp > 0 && hp > 0) {
        cout << "\nAlien HP: [" << alien_hp << "] | Your HP: [" << hp << "]" << endl;
        cout << "1. Heavy Punch\n2. Tactical Dodge\n> ";
        int move = get_valid_input();
        
        // --- PLAYER'S TURN ---
        if (move == 1) {
            int hit_roll = rand() % 100; // Use 0-99 for better precision
            
            if (hit_roll < 85) { // 85% Hit Chance
                int dmg = rand() % 15 + 10;
                
                // Critical Hit Logic (15% chance for double damage)
                if (hit_roll < 15) { 
                    dmg *= 2;
                    cout << "CRITICAL HIT! You slam the alien for " << dmg << " damage!" << endl;
                } else {
                    cout << "You land a solid punch for " << dmg << "!" << endl;
                }
                alien_hp -= dmg;
            } else {
                cout << "The alien blurred out of the way! You missed!" << endl;
            }
        } else {
            cout << "You're focused and ready to move..." << endl;
        }
        
        // --- ALIEN'S TURN ---
        if (alien_hp > 0) {
            int a_dmg = (alien_hp < 40) ? (rand() % 25 + 10) : (rand() % 15 + 5);

            if (move == 2) {
                a_dmg /= 3;
                cout << "You rolled away! The alien only dealt " << a_dmg << " damage." << endl;
            } else {
                cout << "The alien lashes out for " << a_dmg << " damage!" << endl;
            }
            
            hp -= a_dmg;
            if (hp < 0) hp = 0;
        }
    }
    
    if (hp > 0) cout << "\nThe alien screeches and retreats into the vents!" << endl;
}

void shed_search() {
    cout << "\nYou find the alien's bag. Inside is a translator." << endl;
    has_translator = true;
    cout << "1. Use it on the wall carvings\n2. Run away\n> ";
    if (get_valid_input() == 1) decode_cover();
}

void decode_cover() {
    if (has_translator) {
        cout << "\nThe wall says: 'Earth is a 1-star resort.' Ouch." << endl;
    } else {
        cout << "\nLooking at the symbols makes your head hurt. -10 HP." << endl;
        hp -= 10;
        check_status();
    }
}

int get_valid_input() {
    turns++; // Every time the player makes a choice, add a turn
    int input;
    while (!(cin >> input)) {
        cout << "Numbers only, please: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    return input;
}
void check_status() {
    if (hp <= 0) {
        hp = 0;
        cout << "\n--- DEATH HAS ARRIVED ---" << endl;
        cout << "Turns Survived: " << turns << endl; // Show score on death
        cout << "Your vision fades to black..." << endl;
    } else {
        cout << "[Current HP: " << hp << " | Turn: " << turns << "]" << endl;
    }
}

#endif 