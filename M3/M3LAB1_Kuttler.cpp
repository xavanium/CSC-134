/*
CSC 134
Kuttlerj6796
M3LAB1 
started 2/18/26
*/

#include <iostream>
using namespace std;

// List PROTOTYPES of all the choices up here
// rename these to something that makes sense!
void walk_inside();
void walk_past();
void leave_potion();
void investigate();
void shed_search();
void open_book();
void decode_cover();
// main() goes here
int main() {

    int choice;
    // main() starts the game
    cout << "GAME TITLE" << endl << endl;
    cout << "You're going about your day when you stumble upon a mysterious shed.." << endl;
    cout << "Do You: " << endl; // make these into real choices!
    cout << "1. Walk inside" << endl;
    cout << "2. Leave it alone" << endl;

    cout << "> "; // Give them a prompt to type
    cin >> choice;

    if (1 == choice) {
        walk_inside();
    }
    else if (2 == choice) {
        walk_past();
    }
    else {
        cout << "I didn't understand that." << endl;
    }
    cout << "*GAME OVER*" << endl << endl;

    return 0; // end of game
}

// List FULL FUNCTIONS of all the choices at the bottom
void walk_inside() {
    int choice;
    cout << "You walk inside.." << endl;
    cout << "There is a potion on a table." << endl;
    cout << "Do you... " << endl;
    cout << "1. Drink it" << endl;
    cout << "2. Leave it alone" << endl;
    cout << "> ";
    cin >> choice;
    if (choice == 1){
        cout << "Poison!!!! Death!!!" << endl;
    } else if (choice == 2){
        leave_potion();
    } else {
        cout << "You don't make sense";
    }
}

void walk_past() {
    cout << "You walk past the shed." << endl;
    cout << "You get hit by an asteroid and die." << endl;
    cout << "The end." << endl;
}

void leave_potion(){
    int choice;
    cout << "You leave the potion." << endl;
    cout << "But then you hear a loud crash outside, what do you do?" << endl; 
    cout << "1. Investigate" << endl;
    cout << "2. Search the shed" << endl;
    cout << "> ";
    cin >> choice;
    if (choice == 1){
        investigate();
    } else if (choice == 2){
        shed_search();
    } else {
        cout << "You don't make sense";
    }
}

void investigate(){
    cout << "You step outside the shed." << endl;
    cout << "You realize it was an asteroid crashing on earth." << endl;
    cout << "But then another one crashes down and you die." << endl;
}

void shed_search(){
    int choice;
    cout << "You find a book with a cover that's in an alien language." << endl;
    cout << "Do you..." << endl;
    cout << "1. Open it" << endl;
    cout << "2. Try to decode the cover" << endl;
    cout << "> ";
    cin >> choice;
    if (choice == 1){
        open_book();
    } else if (choice == 2){
        decode_cover();
    } else {
        cout << "You don't make sense";
    }
}
void open_book(){
    cout << "You find detailed diagrams of alien biology." << endl;
    cout << "Then you find a diagram of the real Joe Budden before he was replaced by a body double." << endl;
    cout << "You realize aliens abducted him and dissected his body, and the one walking among us today is an alien spy." << endl;
    cout << "Then the CIA shows up and puts you to sleep and takes you away." << endl;
    cout << "Long Live Your Alien Overlords." << endl;
    cout << "🛸🛸🛸🛸🛸🛸🛸🛸🛸🛸🛸🛸🛸" << endl;
}
void decode_cover(){
    cout << "It is too much for your puny human brain to understand." << endl;
    cout << "Your brain collapses into a black hole and you die." << endl;
    cout << "🛸🛸🛸🛸🛸🛸🛸🛸🛸🛸🛸🛸🛸"<< endl;
}
