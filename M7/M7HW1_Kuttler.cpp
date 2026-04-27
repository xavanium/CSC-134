/* CSC 134
M7HW1/PROJECT -- Mastermind esque
4.27.26
Kuttlerj6796 */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void getFeedback(const vector<int>& secret, const vector<int>& guess, int& correctPos, int& correctNum) {
    correctPos = 0;
    correctNum = 0;
    vector<bool> secretUsed(4, false);
    vector<bool> guessUsed(4, false);

    // First pass: Check for correct positions
    for (int i = 0; i < 4; i++) {
        if (guess[i] == secret[i]) {
            correctPos++;
            secretUsed[i] = true;
            guessUsed[i] = true;
        }
    }

    // Second pass: Check for correct numbers in wrong positions
    for (int i = 0; i < 4; i++) {
        if (!guessUsed[i]) {
            for (int j = 0; j < 4; j++) {
                if (!secretUsed[j] && guess[i] == secret[j]) {
                    correctNum++;
                    secretUsed[j] = true;
                    break;
                }
            }
        }
    }
}

int main() {
    srand(time(0));
    vector<int> secretCode;
    for (int i = 0; i < 4; i++) {
        secretCode.push_back(rand() % 6 + 1); // Numbers 1 to 6
    }

    cout << "--- Welcome to Mastermind ---" << endl;
    cout << "Guess the 4-digit code (numbers 1-6)." << endl;
    cout << "You have 10 attempts!" << endl;

    int attempts = 10;
    while (attempts > 0) {
        vector<int> guess(4);
        cout << "\nAttempts left: " << attempts << "\nEnter your guess (4 numbers separated by spaces): ";
        
        for (int i = 0; i < 4; i++) cin >> guess[i];

        int correctPos, correctNum;
        getFeedback(secretCode, guess, correctPos, correctNum);

        if (correctPos == 4) {
            cout << "CONGRATULATIONS! You broke the code!" << endl;
            return 0;
        }

        cout << "Feedback: [" << correctPos << "] Correct Position, [" << correctNum << "] Correct Number but wrong spot." << endl;
        attempts--;
    }

    cout << "\nGame Over! The code was: ";
    for (int n : secretCode) cout << n << " ";
    cout << endl;

    return 0;
}