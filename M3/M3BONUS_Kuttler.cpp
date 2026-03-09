#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Game State Variables
int hp = 100;
int alien_hp = 50;
bool has_translator = false;
string current_passage = "Start";

void clear_screen() {
    // Simple way to keep the console clean
    cout << "\n------------------------------------------\n";
}

int main() {
    srand(time(0)); // Seed for random numbers

    while (current_passage != "Exit") {
        clear_screen();
        cout << "HP: " << hp << " | State: " << current_passage << endl;

        if (current_passage == "Start") {
            cout << "--- ALIEN SHED: SURVIVAL ---\n";
            cout << "You see the shed ahead.\n";
            cout << "1. Enter the shed\n2. Walk past it\nChoice: ";
            int choice; cin >> choice;
            if (choice == 1) current_passage = "WalkInside";
            else current_passage = "WalkPast";
        }

        else if (current_passage == "WalkInside") {
            cout << "You enter. A vial of 'Glowing Goop' sits there.\n";
            cout << "1. Drink it\n2. Ignore it\nChoice: ";
            int choice; cin >> choice;
            if (choice == 1) current_passage = "DrinkGoop";
            else current_passage = "LeavePotion";
        }

        else if (current_passage == "WalkPast") {
            int damage = (rand() % 51) + 10; // Random 10 to 60
            hp -= damage;
            cout << "An asteroid fragments nearby! Shrapnel hits you for " << damage << " damage.\n";
            if (hp <= 0) current_passage = "GameOver";
            else {
                cout << "You're hurt, but you limp away to safety.\n";
                current_passage = "SurvivalEnding";
            }
        }

        else if (current_passage == "DrinkGoop") {
            cout << "It tastes like battery acid! You lose 40 HP.\n";
            hp -= 40;
            if (hp <= 0) current_passage = "GameOver";
            else current_passage = "LeavePotion";
        }

        else if (current_passage == "LeavePotion") {
            cout << "A heavy metallic THUD sounds behind you. A 7-foot tall alien stands there!\n";
            cout << "1. Fight back\n2. Try to talk\nChoice: ";
            int choice; cin >> choice;
            if (choice == 1) {
                alien_hp = 50;
                current_passage = "CombatLoop";
            } else current_passage = "TalkToAlien";
        }

        else if (current_passage == "TalkToAlien") {
            cout << "It doesn't want to talk. It punts you across the room! -30 HP.\n";
            hp -= 30;
            if (hp <= 0) current_passage = "GameOver";
            else current_passage = "ShedSearch";
        }

        else if (current_passage == "CombatLoop") {
            cout << "Alien HP: " << alien_hp << " | Your HP: " << hp << endl;
            cout << "1. Punch\n2. Dodge\nChoice: ";
            int choice; cin >> choice;
            
            // Player Action
            int player_dmg = 0;
            bool dodging = false;
            if (choice == 1) {
                player_dmg = (rand() % 21) + 5;
                alien_hp -= player_dmg;
                cout << "You land a hit for " << player_dmg << "!\n";
            } else {
                dodging = true;
                cout << "You prepare to dodge!\n";
            }

            // Alien Action
            if (alien_hp > 0) {
                int alien_dmg = rand() % 26;
                if (dodging) alien_dmg /= 2;
                hp -= alien_dmg;
                cout << "The alien strikes for " << alien_dmg << " damage!\n";
            }

            // Check health
            if (hp <= 0) current_passage = "GameOver";
            else if (alien_hp <= 0) {
                cout << "The alien retreats into the shadows!\n";
                current_passage = "ShedSearch";
            }
            // If both alive, loop stays on CombatLoop
        }

        else if (current_passage == "ShedSearch") {
            cout << "You find the alien's bag. Inside is a translator.\n";
            has_translator = true;
            cout << "1. Use it on wall carvings\n2. Run away\nChoice: ";
            int choice; cin >> choice;
            if (choice == 1) current_passage = "DecodeCover";
            else current_passage = "SurvivalEnding";
        }

        else if (current_passage == "DecodeCover") {
            if (has_translator) {
                cout << "The wall says: 'Earth is a 1-star resort.' Ouch.\n";
                current_passage = "SurvivalEnding";
            } else {
                cout << "Looking at the symbols makes your head hurt. -10 HP.\n";
                hp -= 10;
                if (hp <= 0) current_passage = "GameOver";
                else current_passage = "SurvivalEnding";
            }
        }

        else if (current_passage == "SurvivalEnding") {
            cout << "\n*** YOU SURVIVED! ***\n";
            cout << "Play again? (1: Yes, 2: No): ";
            int choice; cin >> choice;
            if (choice == 1) { hp = 100; current_passage = "Start"; }
            else current_passage = "Exit";
        }

        else if (current_passage == "GameOver") {
            cout << "\n*** YOUR JOURNEY ENDS HERE ***\nHP hit 0.\n";
            cout << "Try again? (1: Yes, 2: No): ";
            int choice; cin >> choice;
            if (choice == 1) { hp = 100; current_passage = "Start"; }
            else current_passage = "Exit";
        }
    }

    cout << "Goodbye!" << endl;
    return 0;
}