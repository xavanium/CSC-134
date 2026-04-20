/* CSC 134
M6LAB2 - Room Arrays
Kuttlerj6796
4/20/26*/

#include <iostream>
using namespace std;
int main() {
    const int NUM_ROOMS = 5, NUM_DIRECTIONS = 4;
    string room_names[NUM_ROOMS] {
        "The Door",
        "Awesome Room",
        "Based Room",
        "Cringe Room",
        "Pulchritudinous Room"
    };
    string room_descriptions[NUM_ROOMS] {
        "A door.",
        "A room that's pretty awesome.",
        "A room that's pretty based, but based on what?",
        "A room that's pretty cringe.",
        "A room that's pretty; so pretty that it's pulchritudinous.."
    };
    int connections[NUM_ROOMS][NUM_DIRECTIONS];
    return 0;
}