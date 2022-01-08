#include <iostream>
#include <string>

using namespace std;

/* SUCCESS: "1521" */
int main() { 
    FILE* fp = fopen("day1.txt", "r");

    // Cannot open file
    if ( fp == NULL ) {
        exit(-1);
    }

    int cur = -1, prev = -1;
    int cnt = 0;
    // Main execution
    
    while ( fscanf(fp, "%d", &cur) == 1 ) {
        if ( -1 == prev ) {
            prev = cur;
            continue;
        }

        if (cur > prev) {
            cnt++;
        }

        prev = cur;

    }
    fclose(fp);

    cout << cnt << endl;
    return 0;
}
