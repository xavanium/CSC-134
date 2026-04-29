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
    std::cout << "name = " << name << std::endl;
    std::cout << "pName = " << pName << std::endl;
    std::cout << "*pName = " << *pName << std::endl;
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