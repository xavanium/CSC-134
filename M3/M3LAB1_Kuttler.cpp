/*
CSC 134
Kuttlerj6796
M3LAB1 - Survival Edition
Added: HP System, Damage Mechanics, and Combat
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// --- GLOBALS ---
bool has_translator = false;
int hp = 100; // Starting Health

// --- PROTOTYPES ---
void walk_inside();
void walk_past();
void leave_potion();
void shed_search();
void decode_cover();
void alien_boss_fight();
int get_valid_input();
void check_status(); // New: Checks if player is dead

int main() {
    srand(time(0));
    char play_again;

    do {
        // Reset for new game
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

// --- NEW HELPER: DAMAGE SYSTEM ---
void check_status() {
    if (hp <= 0) {
        cout << "Your HP has hit 0. You collapsed!" << endl;
    } else {
        cout << "[Current HP: " << hp << "]" << endl;
    }
}

void walk_inside() {
    cout << "\nYou enter. A vial of 'Glowing Goop' sits there." << endl;
    cout << "1. Drink it\n2. Ignore it\n> ";
    if (get_valid_input() == 1) {
        cout << "It tastes like battery acid! You lose 40 HP." << endl;
        hp -= 40;
        check_status();
    }
    
    if (hp > 0) leave_potion();
}

void walk_past() {
    cout << "\nAn asteroid fragments nearby!" << endl;
    int damage = rand() % 50 + 10; // Random damage 10-60
    cout << "Shrapnel hits you for " << damage << " damage." << endl;
    hp -= damage;
    check_status();
    
    if (hp > 0) {
        cout << "You're hurt, but you limp away to safety." << endl;
    }
}

void leave_potion() {
    cout << "\nYou hear a heavy metallic THUD behind you." << endl;
    cout << "A 7-foot tall grey alien stands in the doorway!" << endl;
    cout << "1. Fight back\n2. Try to talk\n> ";
    
    if (get_valid_input() == 1) alien_boss_fight();
    else {
        cout << "It doesn't want to talk. It punts you across the room." << endl;
        hp -= 30;
        check_status();
        if (hp > 0) shed_search();
    }
}

void alien_boss_fight() {
    cout << "\n--- COMBAT COMMENCED ---" << endl;
    int alien_hp = 50;
    
    while (alien_hp > 0 && hp > 0) {
        cout << "Alien HP: " << alien_hp << " | Your HP: " << hp << endl;
        cout << "1. Punch\n2. Dodge\n> ";
        int move = get_valid_input();
        
        if (move == 1) {
            int dmg = rand() % 20 + 5;
            cout << "You land a hit for " << dmg << "!" << endl;
            alien_hp -= dmg;
        } else {
            cout << "You prepared to dodge!" << endl;
        }
        
        // Alien attacks
        if (alien_hp > 0) {
            int a_dmg = rand() % 25;
            if (move == 2) a_dmg /= 2; // Taking half damage if dodging
            cout << "The alien strikes for " << a_dmg << " damage!" << endl;
            hp -= a_dmg;
        }
    }
    
    if (hp > 0) cout << "The alien retreats into the shadows!" << endl;
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
    int input;
    while (!(cin >> input)) {
        cout << "Numbers only, please: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    return input;
}