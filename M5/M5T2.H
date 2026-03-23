#ifndef M5T2_H_INCLUDED
#define M5T2_H_INCLUDED
#include <fstream>
#include <iostream>
using namespace std;

int square(int num) {
    // input: a number
    // output: the number, squared
    int answer = num * num;
    return answer;
}

void print_table_line(int first, int second) {
    // input: two numbers
    // effect: prints a line with both numbers
    cout << first << "\t" << second << endl;
}
void write_squares_table(string filename, int start, int finish) {
    //input: file name, first number, last number
    //effect: writes a table of squares from first to last to the file
    ofstream outfile;
    outfile.open(filename);
    if(outfile) {
       for (int i = start; i<=finish; i++) {
        int sq = square(i);
        outfile << i << " " << sq << endl;
        
       }
       outfile.close();
    }
    else {
         cout << "Could not open file: " << filename << endl;
        return;
    }
    
}
#endif // M5T2_H_INCLUDED