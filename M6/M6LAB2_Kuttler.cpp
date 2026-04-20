/* CSC 134
M6LAB2 - Room Arrays
Kuttlerj6796
4/20/26*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. Setup Constants and Enums
    const int NUM_ROOMS = 5;
    const int NUM_DIRECTIONS = 4;
    
    enum Rooms { DOOR, AWESOME, BASED, CRINGE, PULCH_ROOM };
    enum Directions { NORTH, EAST, SOUTH, WEST };

    // 2. Parallel Arrays [cite: 42]
    string room_names[NUM_ROOMS] = {
        "The Door", "Awesome Room", "Based Room", "Cringe Room", "Pulchritudinous Room"
    };

    string room_descriptions[NUM_ROOMS] = {
        "A door.",
        "A room that's pretty awesome.",
        "A room that's pretty based, but based on what?",
        "A room that's pretty cringe.",
        "A room that's so pretty that it's pulchritudinous."
    };

    // 3. The Adjacency List (The Map) [cite: 44]
    // Format: {North, East, South, West}
    int connections[NUM_ROOMS][NUM_DIRECTIONS] = {
        {AWESOME, -1, -1, -1},       // DOOR
        {-1, BASED, DOOR, -1},       // AWESOME
        {CRINGE, -1, -1, AWESOME},   // BASED
        {-1, PULCH_ROOM, BASED, -1}, // CRINGE
        {-1, -1, -1, CRINGE}         // PULCH_ROOM
    };

    // 4. Game Loop Variables
    int current_room = DOOR;
    string choice;
    bool keep_playing = true;

    cout << "--- Welcome to the Dungeon ---" << endl;

    while (keep_playing) {
        // Show current location 
        cout << "\nLocation: " << room_names[current_room] << endl;
        cout << room_descriptions[current_room] << endl;
        cout << "Directions: (north, east, south, west) or 'quit'" << endl;
        cout << "> ";
        cin >> choice;

        int direction;
        if (choice == "north") direction = NORTH;
        else if (choice == "east") direction = EAST;
        else if (choice == "south") direction = SOUTH;
        else if (choice == "west") direction = WEST;
        else if (choice == "quit") {
            keep_playing = false;
            continue;
        } else {
            cout << "I don't understand that command." << endl;
            continue;
        }

        // Move logic [cite: 14, 18]
        int next_room = connections[current_room][direction];

        if (next_room == -1) {
            cout << "You can't go that way!" << endl;
        } else {
            current_room = next_room;
        }
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}