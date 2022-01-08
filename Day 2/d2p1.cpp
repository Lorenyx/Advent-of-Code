#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream infile ("day2.txt");
    string buffer;
    int x=0, y=0;
    int val;

    while (infile >> buffer >> val) {
        // cout << buffer << "-" << val << endl;
        switch (buffer[0]) {
            case 'f': // forward
                x += val;
                break;
            case 'u': // up
                y -= val;
                break;
            case 'd': // down
                y += val;
                break;
        }
    }

    cout << (x * y) << endl;

    return 0;
}