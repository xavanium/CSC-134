/* 
CSC 134
Kuttlerj6796
2.25.26
M3HW1 - Gold of course cuz im a fricken genius and a genetic freak
*/

#include <iostream>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

void walk_inside();
void walk_past();
void leave_potion();
void investigate();
void shed_search();
void open_book();
void decode_cover();
int main(){
    string answer;
    cout << "Question 1: " << endl;
    cout << "Hello, I'm a C++ program! Do you like me?" << endl;
    cin >> answer;
    if (answer=="yes"){
        cout << "YAYYYYYYYYY!!!! :333333" << endl;
    } else if (answer=="no"){
        cout << "Oh.. okay :(" << endl;
    } else {
        cout << "I don't even know what you're saying!!!" << endl;
    }
    cout << endl;
    cout << "Question 2: " << endl;
    string meal_name;
    string where;
    int num_meals, inOrOut;
    double tax_rate = 0.08;
    double tip_amount;
    double tax_amount;
    double total_price; // meal+tip+tax
    double subtotal;
    double meal_price;
    cout << fixed << setprecision(2);
    cout << "Welcome to the CSC 134 Eatery!" << endl;
    cout << "What would you like to order? " << endl;
    cin >> meal_name;
    cout << "How much does that cost again?" << endl;
    cin >> meal_price;
    cout << "Enter 1 for dine in or 2 for takeout: ";
    cin >> inOrOut;
    if (inOrOut==1){
        where = "Dine In";
        tip_amount = meal_price * 0.15;
    } else {
        where = "Takeout";
        tip_amount = 0;
    }
    cout << fixed << setprecision(2);
    cout << "--------------------------" << endl;
    cout << "YOU ORDERED: \t\t\t" << meal_name << endl;
    cout << "SUBTOTAL: \t\t\t$" << meal_price << endl;
    cout << "TAX PRICE: \t\t\t$" << meal_price * 0.08 << endl;
    cout << "TIP AMOUNT: \t\t\t$" << tip_amount << endl;
    cout << "TOTAL: \t\t\t\t$" << meal_price + meal_price * tax_amount + tip_amount << endl;
    cout << "--------------------------" << endl;
    cout << endl;
    cout << "Question 3: " << endl;

    int choice;
    cout << "ALIEN SHED (CYOA)" << endl << endl;
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
    
    cout << "Question 4: " << endl;
    srand(time(0));
    int randNum1 = rand() % 10;
    int randNum2 = rand() % 10;
    int sum;
    cout << "What's " << randNum1 << " + " << randNum2 << "?" << endl;
    cin >> sum;
    if (sum==randNum1 + randNum2){
        cout << "Correct!";
    } else {
        cout << "Incorrect.";
    }
    cout << endl;
    return 0;
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