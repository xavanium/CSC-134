/*
M6LAB1 - Slime Roulette (Pro Edition)
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

    cout << "--- SLIME ROULETTE: PRO EDITION ---" << endl;
    cout << "New Item: Type '3' to use your Magnifying Glass (Once per reload)!" << endl;

    while (playerAlive) {
        int playerHP = 4, dealerHP = 4; 
        cout << "\n========================================";
        cout << "\n>>> CURRENT STREAK: " << roundsWon << " | ENTERING ROUND " << (roundsWon + 1) << " <<<" << endl;
        
        while (playerHP > 0 && dealerHP > 0) {
            loadMagazine(magazine, 4, 4); 
            bool playerTurn = true;
            bool canPeek = true; // One peek per reload

            while (!magazine.empty() && playerHP > 0 && dealerHP > 0) {
                displayMagazine(magazine);
                
                if (playerTurn) {
                    int choice = 0;
                    cout << "\n[YOU] HP: " << playerHP << " | [DEALER] HP: " << dealerHP << endl;
                    cout << "1. Shoot Dealer\n2. Shoot Yourself\n" << (canPeek ? "3. Use Magnifying Glass (PEEK)\n" : "") << "Choice: ";
                    
                    while (!(cin >> choice) || (choice < 1 || choice > 3) || (choice == 3 && !canPeek)) {
                        cout << "Invalid choice: ";
                        cin.clear(); cin.ignore(100, '\n');
                    }

                    if (choice == 3) {
                        cout << ">> You look into the chamber... The next shell is: " << (magazine.back() == 'S' ? "SLIME" : "WATER") << "!" << endl;
                        canPeek = false;
                        continue; // Doesn't end turn
                    }

                    char result = fireShot(magazine);
                    if (choice == 2) { 
                        if (result == 'S') {
                            cout << ">> KERSPLAT! -1 HP." << endl;
                            playerHP--; playerTurn = false; 
                        } else {
                            cout << ">> CLICK. Water. GO AGAIN." << endl;
                        }
                    } else { 
                        if (result == 'S') {
                            cout << ">> BOOM! Dealer hit! -1 HP." << endl;
                            dealerHP--;
                        } else {
                            cout << ">> CLICK. Dealer safe." << endl;
                        }
                        playerTurn = false;
                    }
                } 
                else { // Dealer AI
                    int sCount = 0, wCount = 0;
                    for(char c : magazine) (c == 'S') ? sCount++ : wCount++;
                    bool shootSelf = (wCount > sCount);
                    
                    cout << "\n[DEALER] targets " << (shootSelf ? "THEMSELVES." : "YOU.") << endl;
                    char result = fireShot(magazine);
                    if (shootSelf) {
                        if (result == 'S') {
                            cout << ">> KERSPLAT! Dealer hit. -1 HP." << endl;
                            dealerHP--; playerTurn = true;
                        } else {
                            cout << ">> CLICK. Dealer extra turn." << endl;
                        }
                    } else {
                        if (result == 'S') {
                            cout << ">> BOOM! You hit. -1 HP." << endl;
                            playerHP--;
                        } else {
                            cout << ">> CLICK. You safe." << endl;
                        }
                        playerTurn = true;
                    }
                }
            }
        }

        if (playerHP <= 0) {
            playerAlive = false;
            cout << "\nGAME OVER. Final Streak: " << roundsWon << endl;
        } else {
            roundsWon++;
            cout << "\nVICTORY! Round " << roundsWon << " cleared." << endl;
        }
    }
    return 0;
}

void loadMagazine(vector<char>& mag, int slime, int water) {
    mag.clear(); 
    for (int i = 0; i < slime; i++) mag.push_back('S');
    for (int i = 0; i < water; i++) mag.push_back('W');
    random_device rd; mt19937 gen(rd()); shuffle(mag.begin(), mag.end(), gen);
    cout << "\n* 8-shot magazine loaded (" << slime << "S, " << water << "W) *" << endl;
}

void displayMagazine(const vector<char>& mag) {
    int s = 0, w = 0;
    for (char shell : mag) (shell == 'S') ? s++ : w++;
    cout << "\n[ Mag: " << s << "S / " << w << "W ]";
}

char fireShot(vector<char>& mag) {
    char shell = mag.back(); mag.pop_back(); return shell;
}