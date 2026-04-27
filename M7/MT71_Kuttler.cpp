/* CSC 134
M7T1 - Classes (Star Display Edition)
4/27/26 
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath> // For floor()

using namespace std;

class Restaurant {
    private:
        string name;
        double rating;

    public:
        Restaurant(string n, double r) : name(n), rating(r) {}

        // Setters and Getters
        void setName(string n) { name = n; }
        void setRating(double r) { rating = (r >= 0 && r <= 5) ? r : 0; }
        string getName() const { return name; }
        double getRating() const { return rating; }

        // The Star logic
        void printStars() const {
            int fullStars = static_cast<int>(rating); // Get the whole number
            double fractionalPart = rating - fullStars;

            cout << "Rating: ";
            // Print full stars
            for (int i = 0; i < fullStars; ++i) {
                cout << "*";
            }

            // Print half star if the decimal is 0.5 or higher
            if (fractionalPart >= 0.5) {
                cout << "½";
            }

            cout << " (" << fixed << setprecision(1) << rating << "/5.0)" << endl;
        }

        void display() const {
            cout << "\n============================" << endl;
            cout << "RESTAURANT: " << name << endl;
            printStars();
            cout << "============================" << endl;
        }
};

int main() {
    string name;
    double rating;

    cout << "Enter restaurant name: ";
    getline(cin, name);

    cout << "Enter rating (e.g., 3.5, 4.0): ";
    cin >> rating;

    Restaurant rest1(name, rating);
    rest1.display();

    return 0;
}