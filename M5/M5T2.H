C

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
    
    void read_squares_table(string filename) {
        //input: filename to open
        //effect: print out data (assuming two numbers per line)
        ifstream infile;
        infile.open(filename);
        if (infile) {
            //file is ok
            int num1, num2;
            while (infile >> num1 >> num2) {
                //read 2 numbers at a time 
                cout << num1 << "\t" << num2 << endl;
            }
        } else {
            //file cant open
            cout << "Error: couldnt open " << filename << endl;
            return;
        }
    }
#endif // M5T2_H_INCLUDED