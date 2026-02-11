/*
M3T1
Compare two triangles
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    //program: measure two rectangles
    //declare variables
    double length1, width1, area1;
    double length2, width2, area2;
    //get inpuy from the user
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
    cout << fixed << setprecision(2) << endl;
    cout << "The area of the first rectangle is " << area1 << endl;
    cout << "The area of the second tectangle is " << area2 << endl << endl;
    return 0;
}