// M5T2 - Functions Practice
// kuttlerj6796
// 3/23/26


#include <iostream>
#include "M5T2.H"
using namespace std;

int main()
{
    // print out a table of squares
    cout << "Num\tSquare" << endl;
    int start  = 1;
    int finish = 10;
    for (int num=start; num <= finish; num++) {
        int sq = square(num);
        print_table_line(num, sq);

    }
    //write to a file
    string filename = "squares.txt";
    write_squares_table(filename, start, finish);
    return 0;
}