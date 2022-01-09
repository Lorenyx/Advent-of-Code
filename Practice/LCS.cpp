#include <iostream>
#include <string>
#include <vector>

using namespace std;

int LCSLength(string x, string y) {
    int m = x.length(), n = y.length();

    int lookup[m + 1][n + 1];

    for (int i=0; i <= m || i <= n; i++) {
        if (i <= n)
            lookup[0][i] = 0;
        if (i <= m)
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

string LCSSequence(string x, string y) {
    int m = x.length(), n = y.length();

    int lookup[m + 1][n + 1];
    string retval = "";

    for (int i=0; i <= m || i <= n; i++) {
        if (i <= n)
            lookup[0][i] = 0;
        if (i <= m)
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
    
    int index = lookup[m][n];
    char lcs[index+1];
    lcs[index] = '\0';

    int i=m, j=n;
    while (i > 0 && j > 0) {
        if (x[i-1] == y[j-1]) {
            lcs[index-1] = x[i-1];
            i--; j--; index--;
        }
        else if (lcs[i-1] > lcs[j-1])
            i--;
        else
            j--;
    }
    return lcs;
}

int main()
{
    string X = "xyz", Y = "xaz";
 
    cout << "The length of the LCS is " << LCSLength(X, Y) << endl;
    cout << "The LCS is " << LCSSequence(X, Y) << endl; // only prints first one
 
    return 0;
}