/*
CSC-134
M2T2 - Recepit Calculator
1/26/26
Jacob Kuttler / kuttlerj6796
Goal: A correct looking receipt 
Assumption for tax rate is 8% 
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    //Declare all variables
    //Get user input
  
    //Do the calculation
    //Present the output
    string meal_name = "Burger Platter";
    int num_meals;
    double meal_price = 5.99;
    double tax_rate = 0.08;
    double tip_amount;
    double tax_amount;
    double total_price; // meal+tip+tax
    double subtotal;

    cout << "Welcome to the CSC 134 Burger Emporium!" << endl;
    cout << "Today's special: " << meal_name << endl;
    cout << "How many would you like? ";
    cin >> num_meals;
    subtotal = num_meals * meal_price;

    cout << "YOUR ORDER: " << endl << "-----------------" << endl;
    cout << num_meals << "x " << meal_name << "\t$" << meal_price << endl;
    cout << "Subtotal: \t\t$" << subtotal << endl;



    return 0;
}