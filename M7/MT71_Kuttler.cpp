/* CSC 134
M7T1 - Classes (Refactored)
4/27/26 
*/

#include <iostream>
#include <string>
#include <iomanip> // For output formatting

using namespace std;

class Restaurant {
    private:
        string name;
        double rating;

    public:
        // Using a Member Initializer List here
        Restaurant(string n, double r) : name(n), rating(r) {}

        // Setters
        void setName(string n) { name = n; }
        void setRating(double r) {
            if (r >= 0 && r <= 5.0) {
                rating = r;
            } else {
                rating = 0; // Default fallback
            }
        }

        // Getters
        string getName() const { return name; }
        double getRating() const { return rating; }

        // Added a helper method to print info easily
        void display() const {
            cout << "\n--- Restaurant Summary ---" << endl;
            cout << "Name:   " << name << endl;
            cout << "Rating: " << fixed << setprecision(1) << rating << "/5.0 stars" << endl;
        }
};

int main() {
    string name;
    double rating;

    cout << "=== Restaurant Review System ===" << endl;
    
    cout << "Enter restaurant name: ";
    getline(cin, name);

    cout << "Enter restaurant rating (0-5): ";
    while (!(cin >> rating) || rating < 0 || rating > 5) {
        cout << "Invalid input. Please enter a number between 0 and 5: ";
        cin.clear(); // Clear error flags
        cin.ignore(1000, '\n'); // Discard bad input
    }

    // Create object
    Restaurant rest1(name, rating);

    // Show the results
    rest1.display();

    return 0;
}