/* CSC 134
Kuttlerj6796
M5HW1 - Gold cuz im a fricken genius and genetic freak
4/1/26 */
#include <iostream>
#include <iomanip>
using namespace std;
void question1();
void question2();
void question3();
void question4();
void question5();

int main(){
    char run_again = 'y';
    while (run_again == 'y' || run_again == 'Y'){
    int choice;
    cout << "1. Average rainfall" << endl << "2. Volume of a hyperrectangle" << endl << "3. Convert to roman numeral" << endl << "4. Area of different shapes" << endl << "5. Calculate distance" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
        while (choice < 1 || choice > 5){
            cout << "Invalid. Input again: ";
            cin >> choice;
        }
        switch (choice){
            case 1:
                question1();
                break;
            case 2:
                question2();
                break;
            case 3:
                question3();
                break;
            case 4:
                question4();
                break;
            case 5:
                question5();
                break;
        }
        cout << "Would you like to run the program again? (y/n)" << endl;
        cin >> run_again;
        cout << endl;
    }
    return 0;
}

void question1(){
    string m1, m2, m3;
    int rf1, rf2, rf3;
    cout << setprecision(2) << fixed;
    cout << "Enter the first month: ";
    cin >> m1;
    cout << "Enter the average rainfall for " << m1 << ": ";
    cin >> rf1;
        while (rf1 < 0){
            cout << "Invalid input. Try again: ";
            cin >> rf1;
        }
    cout << "Enter the second month: ";
    cin >> m2;
    cout << "Enter the average rainfall for " << m2 << ": ";
    cin >> rf2;
        while (rf2 < 0){
            cout << "Invalid input. Try again: ";
            cin >> rf2;
        }
    cout << "Enter the third month: ";
    cin >> m3;
    cout << "Enter the average rainfall for " << m3 << ": ";
    cin >> rf3;
        while (rf3 < 0){
            cout << "Invalid input. Try again: ";
            cin >> rf3;
        }
    double avg = (rf1+rf2+rf3) / 3.0;
    cout << "The average rainfall for " << m1 << ", " << m2 << " and " << m3 << " is " << avg;
    cout << endl;
}

void question2(){
    double height, width, length, area;
    cout << setprecision(2) << fixed;
    cout << "Input the height: ";
    cin >> height;
        while (height < 0){
            cout << "Invalid input. Try again: ";
            cin >> height;
        }
    cout << "Input the width: ";
    cin >> width;
        while (width < 0){
            cout << "Invalid input. Try again: ";
            cin >> width;
        }
    cout << "Input the length: ";
    cin >> length;
        while (length < 0){
            cout << "Invalid input. Try again: ";
            cin >> length;
        }
    area = height*width*length;
    cout << "The area is " << area << endl;
}

void question3(){
    int num;
    string roman;
    cout << "Enter a number (1-10): ";
    cin >> num;
        while (num < 1 || num > 10){
            cout << "Invalid number. Try again: ";
            cin >> num;
    }
    switch (num){ 
        case 1:
            roman = "I";
            break;
        case 2:
            roman = "II";
            break;
        case 3:
            roman = "III";
            break;
        case 4:
            roman = "IV";
            break;
        case 5:
            roman = "V";
            break;
        case 6:
            roman = "VI";
            break;
        case 7:
            roman = "VII";
            break;
        case 8:
            roman = "VIII";
            break;
        case 9:
            roman = "IX";
            break;
        case 10:
            roman = "X";
            break;
    }
    cout << "The roman numeral version of " << num << " is " << roman << endl;
}

void question4(){
    int choice;
    cout << "1. Calculate the area of a Circle" << endl;
    cout << "2. Calculate the area of a Rectangle" << endl;
    cout << "3. Calculate the area of a Triangle" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << setprecision(2) << fixed;
    switch (choice){
        case 1:
            double radius;
            cout << "Input the radius: ";
            cin >> radius;
                while (radius < 0){
                    cout << "Invalid input. Try again: ";
                    cin >> radius;
                }
            cout << "The area is " << radius * 3.14159 << endl;
            break;
        case 2:
            double width, length;
            cout << "Input the width: ";
            cin >> width;
                while (width < 0){
                    cout << "Invalid input. Try again: ";
                    cin >> width;
                }
            cout << "Input the length: ";
            cin >> length;
                while (length < 0){
                    cout << "Invalid input. Try again: ";
                    cin >> length;
                }
            cout << "The area is " << width * length << endl;
            break;
        case 3:
            double base, height;
            cout << "Input the base: ";
            cin >> base;
                while (base < 0){
                    cout << "Invalid input. Try again: ";
                    cin >> base;
                }
            cout << "Input the height: ";
            cin >> height;
                while (height < 0){
                    cout << "Invalid input. Try again: ";
                    cin >> height;
                }
            cout << "The area is " << base*height/2 << endl;
            break;
        case 4:
            cout << "Goodbye I guess." << endl;
            break;
    }
}

void question5(){
    double speed, time, distance;
    cout << "How fast was the vehicle traveling (mph)? ";
    cin >> speed;
        while (speed < 0){
            cout << "Invalid input. Try again: ";
            cin >> speed;
        }
    cout << "How many hours did it travel? ";
    cin >> time;
        while (time < 0){
            cout << "Invalid input. Try again: ";
            cin >> time;
        }
    distance = speed * time;
    cout << "The vehicle traveled " << distance << " miles." << endl;
}
// nyang~