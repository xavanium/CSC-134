/* CSC 134
M7T1 - Classes
Kuttlerj6796
4/27/26 */
using namespace std;
#include <iostream>

class Restaurant {
    private:
        string name;
        double rating;
    public:
        Restaurant(string n, double r);
        void setName(string n);
        void setRating(double r);
        string getName() const;
        double getRating() const;
};

Restaurant::Restaurant(string n, double r){
    name = n;
    rating = r;
}
void Restaurant::setName(string n){
    name = n;
}
void Restaurant::setRating(double r){
    rating = r;
}
string Restaurant::getName() const{
    return name;
}
double Restaurant::getRating() const{
    return rating;
}
int main(){

    return 0;
}