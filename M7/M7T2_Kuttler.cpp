/* CSC 134
M7T2 - Pointers
Kuttlerj6796
4/29/26 */

#include <iostream>

int main(){
    std::string name = "Bob";
    std::string *pName = &name;
    std::string freeWings[5] = {"wing1", "wing2", "wing3", "wing4", "wing5"};
    int age = 33;
    int *pAge = &age;
    std::string *pFreeWings = freeWings;
    std::cout << "name = " << name << std::endl;
    std::cout << "pName = " << pName << std::endl;
    std::cout << "*pName = " << *pName << std::endl;
    return 0;
}