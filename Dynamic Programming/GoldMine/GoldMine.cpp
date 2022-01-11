#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    ifstream infile("goldmine.dat");

    int len, val;  
    while (!infile.eof()) {
        infile >> len;

        int goldmine[len][len];
        int path[len][len];
        
        // populate gold mine with values
        for (int i=0; i<len; i++) {
            for (int j=0; j<len; j++) {
                infile >> val;
                goldmine[i][j] = val; 
            }
        }

        // backtrack to find wealthiest path
        for (int i=len-1; i >= 0; i--) { // start from last column to first
            for (int j=0; j<len; j++) { // row is arbitrary
                if (len-1 == i) { // last column so assign current value
                    path[i][j] = goldmine[i][j];
                }
                int right, right_up, right_down;
                // assign values for max comparison
                right = (len-1 == i) ? 0 :  goldmine[i+1][j];
                right_up = (len-1 == )
            }
        }
    }

    return 0;
}