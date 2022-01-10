#include<iostream>
#include<fstream>
#include<string>
#include<bitset>
using namespace std;

#define LENGTH 12

void printArray(int arr[], int length) {
    for (int i=0; i<length; i++) {
        cout << arr[i];
    }
    cout << endl;
}
// SUCCESS - 741950
// original error was due to not initilizing the array to zeroes.
int main() {
    ifstream infile("day3.txt");
    string buffer;

    int ones[LENGTH], zeroes[LENGTH];
    for (int i=0; i<LENGTH; i++) {
        ones[i] = 0;
        zeroes[i] = 0;
    }
    
    bitset<LENGTH> gamma, epsilon;

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
    }

    for (int i=0; i<LENGTH; i++) {
        if (ones[i] > zeroes[i]) {
            gamma.set(LENGTH - (i+1), true);
        } else {
            epsilon.set(LENGTH - (i+1), true);
        }
    }
    cout << gamma.to_ulong() * epsilon.to_ulong() << endl;
}

