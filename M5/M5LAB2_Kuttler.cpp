/* CSC 134
M5LAB2 - Area of a Rectangle
Kuttlerj6796
3/30/26
*/

#include <iostream>
using namespace std;
double get_length();
double get_width();
double get_area(double width, double length);
void display_data(double width, double length, double area);

int main(){
    double length, width, area;
    length = get_length();
    width = get_width();
    area = get_area(length, width);
    display_data(length, width, area);
    return 0;
}

double get_length(){
    double length;
    cout << "What is the length of the rectangle?" << endl;
    cin >> length;
    return length;
}

double get_width(){
    double width;
    cout << "What is the width of the rectangle?" << endl;
    cin >> width;
    return width;
}

double get_area(double length, double width){
    return length*width;
}

void display_data(double length, double width, double area){
    cout << "Length: " << length << endl;
    cout << "Width: " << width << endl;
    cout << "Area: " << area << endl;
}