#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n, m;
        cin >> n >> m;

        bool replaced[51] = { false,};

        for (int i = 0; i < n; i++) {
            int idx;
            cin >> idx;

            idx = min(idx, m+1-idx);

            if (!replaced[idx]) replaced[idx] = true;
            else replaced[m+1-idx] = true;
        }

        for (int i = 1; i <= m; i++) {
            if (replaced[i]) cout << "A";
            else cout << "B";
        }

        cout << '\n';
    }

    return 0;
}