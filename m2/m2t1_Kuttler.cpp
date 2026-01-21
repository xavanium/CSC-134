// CSC 134
// M2T1 - User runs store
// Jacob Kuttler
// 1/14/26
/* We're selling "foo" -- you decide what that is
Tell the user how many you have,
how much each costs,
and what the total would be

If we have time we'll make it more interactive. */

#include <iostream>
#include <iomanip> // used for decimal point stuff

using namespace std;

int main() {
    //Declare variables at the top, it's easier to read
    string item_name; //change to any thing you want to sell
    int item_count;
    int purchased; //how many user wants
    double price_each;
    double total_price;

    // Set doubles to print with 2 decimal places
    cout << setprecision(2) << fixed;

    cout << "Welcome to our " << item_name << " store." << endl;
    cout << "We have " << item_count << " " << item_name << "." << endl;
    cout << "They cost $" << price_each << " each" << endl;
    
    //Find out how much user wants to buy
    // Calculate the total
    cout << "How much would you like to buy? ";
    cin >> purchased;
    
    total_price = purchased * price_each;
    cout << "You bought " << purchased << " " << item_name << "." << endl;

    cout << "The total price is $" << total_price << endl;
    return 0;
    // WAZAAAAAAAAAAAAAAAAAAAAAAAAAAP
}