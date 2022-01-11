#include<iostream>
#include<fstream>
#include<string>
#include<list>
using namespace std;

#define LENGTH 12

int main() {
    ifstream infile("day3.txt");
    string buffer;
    list<string> vals;
    char gamma[LENGTH+1];
        gamma[LENGTH] = '\0';

    int ones[LENGTH], zeroes[LENGTH];
    // set default values to 0
    for (int i=0; i<LENGTH; i++) {
        ones[i] = 0;
        zeroes[i] = 0;
    }
    
    if ( !infile ) {
        cout << "[-] Cannot open file...\n";
        exit(-1);
    }

    while (infile >> buffer) {
        for (int i=0; i<LENGTH; i++) {
            if (buffer[i] == '1') {
                ones[i]++;
            } else {
                zeroes[i]++;
            }
        }
        vals.push_back(buffer);
    }

    // Create gamma 
    for (int i=LENGTH-1; i>=0; i--) {
        if (ones[i] > zeroes[i]) {
            gamma[i] = '1';
        } else {
            gamma[i] = '0';
        }
    }
    string swp;
    while (vals.size() > 1) {
        swp = vals.front();
        if (swp[0] == )
    }

    return 0;
}