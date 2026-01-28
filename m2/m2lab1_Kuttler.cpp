/*
CSC 134
M2LAB1 - Crates
Kuttlerj6796
1/28/26
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    //Part 1 Set up variables
    //crate variables
    double length, width, height, volume; //in feet
    //Price variabkes
    const double COST_PER_CUBIC_FOOT = 0.23;
    const double CHARGE_PER_CUBIC_FOOT = 0.5;
    double cost, customer_price, profit; //in $
    //Part 2 input
    cout << "Crate Purchase Program" << endl;
    cout << "Enter the size of your crate \n";
    cout << "Length? ";
    cin >> length;
    cout << "Width? ";
    cin >> width;
    cout << "Height? ";
    cin >> height;
    //Part 3 calculation
    volume = length * width * height;
    cost = volume * COST_PER_CUBIC_FOOT;
    customer_price = volume * CHARGE_PER_CUBIC_FOOT;
    profit = customer_price - cost;

    //part 4 output
    cout << setprecision(2) << fixed; // 2 decimal places
    cout << "\n---- CRATE INFO ----\n";
    cout << "Volume: \t\t" << volume << " cubic feet.\n";
    cout << "Cost of production: \t$" << cost << endl;
    cout << "Retail price: \t\t$" << customer_price << endl;
    cout << "Profit: \t\t$" << profit << endl << endl; 
    cout << "\n---- THE STATS ----\n";
    cout << "THANK YOU COME AGAIN\n" << endl;
    // finished i guess ?
    return 0;
}