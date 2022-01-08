#include <iostream>
#include <vector>

using namespace std;

/* SUCCESS: "1543"*/
int main() {
    FILE* fp = fopen("day1.txt", "r");

    vector<int> v;
    int sum_f, sum_b;
    int cnt = 0;
    int swp;

    while (fscanf(fp, "%d", &swp) == 1) {
        v.push_back(swp);
    }
    fclose(fp);

    for (int i=3; i<v.size(); i++) {
        sum_f = v[i-1] + v[i-2] + v[i-3];
        sum_b = v[i] + v[i-1] + v[i-2];

        if (sum_b > sum_f) cnt++;
        
        // cout << "CNT: " << cnt << endl;
    }

    cout << cnt << endl;

    return 0;
}