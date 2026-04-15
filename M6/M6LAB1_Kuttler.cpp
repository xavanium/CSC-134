/*
M6LAB1 - Slime Roulette (Endless Survival)
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
    int roundsWon = 0;
    bool playerAlive = true;

    cout << "--- WELCOME TO ENDLESS SLIME ROULETTE ---" << endl;
    cout << "Survive as many rounds as possible!" << endl;

    // Outer Loop: Keeps the game going until the player dies
    while (playerAlive) {
        int playerHP = 4, dealerHP = 4; // HP Resets every round
        cout << "\n========================================";
        cout << "\n>>> STARTING ROUND " << (roundsWon + 1) << " <<<" << endl;
        cout << "========================================" << endl;

        // Inner Loop: A single round until someone's HP hits 0
        while (playerHP > 0 && dealerHP > 0) {
            loadMagazine(magazine, 3, 3); // Consistent load for fairness
            bool playerTurn = true;

            while (!magazine.empty() && playerHP > 0 && dealerHP > 0) {
                displayMagazine(magazine);
                
                if (playerTurn) {
                    int choice = 0;
                    cout << "\n[PLAYER] HP: " << playerHP << " | [DEALER] HP: " << dealerHP << endl;
                    cout << "1. Shoot Dealer\n2. Shoot Yourself (Extra turn if Water!)\nChoice: ";
                    
                    while (!(cin >> choice) || (choice < 1 || choice > 2)) {
                        cout << "Invalid choice. Pick 1 or 2: ";
                        cin.clear();
                        cin.ignore(100, '\n');
                    }

                    char result = fireShot(magazine);
                    if (choice == 2) { 
                        if (result == 'S') {
                            cout << ">> KERSPLAT! You slimed yourself. -1 HP." << endl;
                            playerHP--;
                            playerTurn = false; 
                        } else {
                            cout << ">> CLICK. It was water! EXTRA TURN." << endl;
                        }
                    } else { 
                        if (result == 'S') {
                            cout << ">> BOOM! Dealer took a slime hit! -1 HP." << endl;
                            dealerHP--;
                        } else {
                            cout << ">> CLICK. Just water. Dealer's turn." << endl;
                        }
                        playerTurn = false;
                    }
                } 
                else { // Dealer AI
                    int sCount = 0, wCount = 0;
                    for(char c : magazine) (c == 'S') ? sCount++ : wCount++;
                    
                    bool shootSelf = (wCount > sCount);
                    cout << "\n[DEALER] shoots " << (shootSelf ? "THEMSELVES." : "YOU.") << endl;

                    char result = fireShot(magazine);
                    if (shootSelf) {
                        if (result == 'S') {
                            cout << ">> KERSPLAT! Dealer slimed themselves! -1 HP." << endl;
                            dealerHP--;
                            playerTurn = true;
                        } else {
                            cout << ">> CLICK. Dealer got water! EXTRA TURN." << endl;
                        }
                    } else {
                        if (result == 'S') {
                            cout << ">> BOOM! You took a slime hit! -1 HP." << endl;
                            playerHP--;
                        } else {
                            cout << ">> CLICK. Dealer fired water at you." << endl;
                        }
                        playerTurn = true;
                    }
                }
            }
        }

        // Check if player survived the round
        if (playerHP <= 0) {
            playerAlive = false;
            cout << "\nGAME OVER! You dropped dead on Round " << (roundsWon + 1) << "." << endl;
        } else {
            roundsWon++;
            cout << "\nVICTORY! You won Round " << roundsWon << ". Preparing next opponent..." << endl;
        }
    }

    cout << "Final Score: " << roundsWon << " rounds survived." << endl;
    return 0;
}

// Full Functions
void loadMagazine(vector<char>& mag, int slime, int water) {
    mag.clear(); 
    for (int i = 0; i < slime; i++) mag.push_back('S');
    for (int i = 0; i < water; i++) mag.push_back('W');
    random_device rd;
    mt19937 gen(rd());
    shuffle(mag.begin(), mag.end(), gen);
    cout << "\n* Dealer loads " << slime << " Slime and " << water << " Water. *" << endl;
}

void displayMagazine(const vector<char>& mag) {
    int s = 0, w = 0;
    for (char shell : mag) (shell == 'S') ? s++ : w++;
    cout << "\n[ Mag: " << s << "S / " << w << "W ]";
}

char fireShot(vector<char>& mag) {
    char shell = mag.back(); 
    mag.pop_back(); 
    return shell;
}