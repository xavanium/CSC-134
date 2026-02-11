/*
M3T2
Compare two rectangles
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    //program: measure two rectangles
    //declare variables
    double length1, width1, area1;
    double length2, width2, area2;
    //get input from the user
    cout << "Please enter the measurements for two rectangles: \n" << endl;
    cout << "Rectangle 1: \n";
    cout << "Length? ";
    cin >> length1;
    cout << "Width? ";
    cin >> width1;
    cout << endl;
        cout << "Rectangle 2: \n";
    cout << "Length? ";
    cin >> length2;
    cout << "Width? ";
    cin >> width2;

    //calculate areas
    area1 = length1*width1;
    area2 = length2*width2;
    //print output
    cout << "The area of the first rectangle is " << area1 << endl;
    cout << "The area of the second tectangle is " << area2 << endl << endl;
    //compare the rectangles now
    if (area1>area2){
        cout << "The first rectangle is largest." << endl;
    }
    else if (area2>area1){
        cout << "The second rectangle is largest." << endl;
    }
    else { //none of the above
        cout << "The areas are the same size." << endl;
    } // done
    return 0;
}