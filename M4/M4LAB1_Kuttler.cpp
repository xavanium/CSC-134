/*m4lab1 - nested loops
kuttlerj6796
3/9/26
*/

#include <iostream>
using namespace std;    
int main(){
    char symbol = 'X';
    string emoji = "🥹";
    
    int height, width;
    cout << "Input height and width: ";
    
    cin >> height >> width;
    //create line of emojis 
    for (int i = 1; i<width; i++){
        cout << emoji << " ";
    }
    cout << endl << endl;
    //create a box of emoji symbols
    cout << endl;
    for (int i = 0; i<height; i++){
        for (int j = 0; j<width; j++){
            cout << emoji << " ";
        }
        cout << endl;
    }
    return 0;
}