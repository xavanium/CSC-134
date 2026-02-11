/* */
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    cout << "Question 1: \n" << endl;
    //question 1 code here
    int actNum;
    string name, action;
    double startBal, deposit = 0, withdrawal = 0, endBal;
    cout << "Welcome to the ATM.\n" << "Please, enter your account name: ";
    getline(cin, name);
    cout << "Enter your account number: ";
    cin >> actNum;
    cout << "Input your starting balance: ";
    cin >> startBal;
    cout << endl;
    cout << "Would you like to deposit or withdrawal? \n";
    cin >> action;
    if (action=="deposit") {
        cout << "Input the amount you would like to deposit: ";
        cin >> deposit;
        endBal = startBal + deposit;
    }
    else if (action=="withdrawal"){
        cout << "Input the amount you would like to withdrawal: ";
        cin >> withdrawal;
        endBal = startBal - withdrawal;
    }
    cout << "Account name: " << name << endl;
    cout << "Account number: " << actNum << endl;
    cout << fixed << setprecision(2);
    cout << "Amount of deposit: $" << deposit << endl;
    cout << "Amount of withdrawal: $" << withdrawal << endl;
    cout << "Final balance: $" << endBal << endl;


    cout << "Question 2: \n" << endl;
    //question 2 code here
     //Part 1 Set up variables
    //crate variables
    double length, width, height, volume; //in feet
    //Price variabkes
    const double COST_PER_CUBIC_FOOT = 0.3;
    const double CHARGE_PER_CUBIC_FOOT = 0.52;
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
    cout << "Profit: \t\t$" << profit; 
    cout << "\n---- THE STATS ----\n";
    cout << "THANK YOU COME AGAIN\n" << endl;
    // finished i guess ?

    cout << "Question 3: " << endl;
    //question 3 code here
    int pizzas, slices, visitors, slicesAte, totalSlices;
    cout << "Pizza Party at the ATC building!\n" << endl;
    cout << "How many pizzas would you like to purchase? ";
    cin >> pizzas;
    cout << "How many slices per pizza? ";
    cin >> slices;
    totalSlices = slices * pizzas;
    cout << "How many visitors will you have? ";
    cin >> visitors;
    cout << "How many slices of pizza will each person get? ";
    cin >> slicesAte;
    cout << endl;
    cout << "There are " << totalSlices - slicesAte*visitors << " slices left over.\n" << endl;
    return 0;
}