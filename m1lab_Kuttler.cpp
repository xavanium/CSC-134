// CSC 134
// M1LAB - Sales
// Jacob Kuttler
// 1/14/26
/* We're selling "foo" -- you decide what that is
Tell the user how many you have,
how much each costs,
and what the total would be

If we have time we'll make it more interactive. */

#include <iostream>
using namespace std;

int main() {
    //Declare variables at the top, it's easier to read
    string item = "bananas"; //change to any thing you want to sell
    int item_count = 100;
    int purchased; //how many user wants
    double price_each = 0.79;
    double total_price;
    cout << "Welcome to our " << item << " store." << endl;
    cout << "We have " << item_count << " " << item << "." << endl;
    cout << "They cost $" << price_each << " each" << endl;
    //Find out how much user wants to buy
    // Calculate the total
    cout << "How much would you like to buy? ";
    cin >> purchased;
    total_price = purchased * price_each;
    cout << "You bought " << purchased << " " << item << "." << endl;

    cout << "The total price is $" << total_price << endl;
    return 0;
}