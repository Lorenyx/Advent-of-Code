#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream infile ("day2.txt");
    string buffer;
    int val;
    int x=0, y=0, aim=0;

    if (!infile) {
        cout << "[-] Could not open file...\n";
        exit(-1);
    }

    while (infile >> buffer >> val) {
        switch (buffer[0]) {
            case 'f': // forward
                x += val;
                y += aim * val;
                break;
            case 'u': // up
                aim -= val;
                break;
            case 'd': // down
                aim += val;
                break;
        }
    }

    cout << (x*y) << endl;
    return 0;
}