/*
M6LAB1 - Slime Roulette
Kuttlerj6796
4/15/26
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

void loadMagazine(vector<char>& mag, int slime, int water);
void displayMagazine(const vector<char>& mag);
char fireShot(vector<char>& mag);

int main() {
    vector<char> magazine;
    int playerHP = 2, dealerHP = 2;
    int round = 1;

    cout << "--- WELCOME TO SLIME ROULETTE ---" << endl;

    while (playerHP > 0 && dealerHP > 0) {
        cout << "\n--- ROUND " << round << " ---" << endl;
        loadMagazine(magazine, 3, 2);
        
        bool playerTurn = true;
        while (!magazine.empty() && playerHP > 0 && dealerHP > 0) {
            displayMagazine(magazine);
            
            if (playerTurn) {
                int choice;
                cout << "\n[PLAYER TURN] HP: " << playerHP << " | Dealer HP: " << dealerHP << endl;
                cout << "1. Shoot Dealer\n2. Shoot Yourself (Extra turn if Water!)\nChoice: ";
                cin >> choice;

                char result = fireShot(magazine);
                if (choice == 2) { // Shooting self
                    if (result == 'S') {
                        cout << "> KERSPLAT! You slimed yourself. -1 HP." << endl;
                        playerHP--;
                        playerTurn = false; // Lose turn on slime
                    } else {
                        cout << "> CLICK. It was water! YOU GET AN EXTRA TURN." << endl;
                        // playerTurn remains true
                    }
                } else { // Shooting dealer
                    if (result == 'S') {
                        cout << "> BOOM! Dealer took a slime hit! -1 HP." << endl;
                        dealerHP--;
                    } else {
                        cout << "> CLICK. Just water. Dealer's turn." << endl;
                    }
                    playerTurn = false;
                }
            } 
            else { // Dealer's Turn
                cout << "\n[DEALER TURN] Thinking..." << endl;
                
                // Simple Dealer Logic: If more water than slime, shoot self. Otherwise, shoot player.
                int sCount = 0, wCount = 0;
                for(char c : magazine) (c == 'S') ? sCount++ : wCount++;
                
                bool shootSelf = (wCount > sCount);
                cout << "Dealer chooses to shoot " << (shootSelf ? "THEMSELVES." : "YOU.") << endl;

                char result = fireShot(magazine);
                if (shootSelf) {
                    if (result == 'S') {
                        cout << "> KERSPLAT! Dealer slimed themselves! -1 HP." << endl;
                        dealerHP--;
                        playerTurn = true;
                    } else {
                        cout << "> CLICK. Dealer got water. DEALER GETS AN EXTRA TURN." << endl;
                        // playerTurn remains false
                    }
                } else {
                    if (result == 'S') {
                        cout << "> BOOM! You took a slime hit! -1 HP." << endl;
                        playerHP--;
                    } else {
                        cout << "> CLICK. Dealer fired water at you." << endl;
                    }
                    playerTurn = true;
                }
            }
        }
        round++;
        cin.ignore(); // Clean up input buffer
    }

    cout << "\n================================" << endl;
    cout << (playerHP <= 0 ? "DEFEAT: You are a puddle." : "VICTORY: The dealer is gone.") << endl;
    return 0;
}

void loadMagazine(vector<char>& mag, int slime, int water) {
    mag.clear(); 
    for (int i = 0; i < slime; i++) mag.push_back('S');
    for (int i = 0; i < water; i++) mag.push_back('W');
    random_device rd;
    mt19937 gen(rd());
    shuffle(mag.begin(), mag.end(), gen);
    cout << "\n* Magazine Loaded: " << slime << " Slime, " << water << " Water *" << endl;
}

void displayMagazine(const vector<char>& mag) {
    int s = 0, w = 0;
    for (char shell : mag) (shell == 'S') ? s++ : w++;
    cout << "\n[ Current Mag: " << s << "S / " << w << "W ]";
}

char fireShot(vector<char>& mag) {
    char shell = mag.back(); 
    mag.pop_back(); 
    return shell;
}