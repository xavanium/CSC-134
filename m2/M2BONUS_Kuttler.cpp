#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    cout << "Problem 1: \n" << endl;
    int height = 8, width = 10;
    cout << "The height of the rectangle is " << height << " and the width is " << width << endl;
    cout << "So the total area is " << height*width << ".\n" << endl;

    cout << "Problem 2: \n" << endl;
    double price = 99.99;
    cout << fixed << setprecision(2);
    cout << "An item is sold for $" << price << "." << endl;
    cout << "The tax price is $" << price*0.08 << "." << endl;
    cout << "The total price is $" << price*0.08+price << ".\n" << endl;

    cout << "Problem 3: \n" << endl;
    int radius = 6;
    const double PI = 3.14;
    double area = PI*radius*radius;
    cout << "A pizza is 12 inches in diameter.\n";
    cout << "Therefore, the area of the pizza is " << area << " inches.\n" << endl;

    cout << "Problem 4: \n" << endl;
    cout << "The area of each slice of said pizza, if it were cut in 8 even pieces, would be " << area/8 << "." << endl << endl;
    return 0;
}