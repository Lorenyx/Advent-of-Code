#include <iostream>
#include <string>

using namespace std;

int LCSLength(string x, string y) {
    int m = x.length(), n = y.length();

    int lookup[m + 1][n + 1];

    for (int i=0; i<=m; i++) {
        lookup[0][i] = 0;
        lookup[i][0] = 0;
    }

    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {

            if (x[i-1] == y[j-1]) {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
            } else {
                lookup[i][j] = max(lookup[i][j-1], lookup[i-1][j]);
            }
        }
    }
    return lookup[m][n];
}

int main()
{
    string X = "abce", Y = "abcde";
 
    cout << "The length of the LCS is " << LCSLength(X, Y) << endl;
 
    return 0;
}