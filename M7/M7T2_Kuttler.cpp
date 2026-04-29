/* CSC 134
M7T2 - Pointers
Kuttlerj6796
4/29/26 */
#include "Rectangle.h"
#include <iostream>
//function prototypes
std::string setName();
void set_name(std::string& name);

int main(){
    std::string name = "Bob";
    std::string *pName = &name;
    //set_name(name);
    std::cout << "name = " << name << std::endl;
    std::cout << "pName = " << pName << std::endl;
    std::cout << "*pName = " << *pName << std::endl;

    //part 2 - rectangles
    Rectangle r1;
    double w, l;
    std::cout << "Enter width and length, separated by a space: ";
    std::cin >> w >> l;
    r1.setLength(l);
    r1.setWidth(w);
    std::cout << "Area is " << r1.getArea() << std::endl;
    r1.drawRectangle();
    return 0;
}

std::string setName(){
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;
    return name;
}

void set_name(std::string& name) {
    std::cout <<"Enter name: ";
    std::cin >> name;
}