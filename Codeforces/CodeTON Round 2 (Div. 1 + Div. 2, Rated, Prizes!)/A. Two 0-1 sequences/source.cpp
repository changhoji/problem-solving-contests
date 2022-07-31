#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n, m;
        cin >> n >> m;

        char a[50], b[50];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        bool flag1 = true;
        for (int i = 1; i <= m-1; i++) {
            if (a[n-i] != b[m-i]) flag1 = false;
        }

        bool flag2 = false;
        for (int i = 0; i < n-m+1; i++) {
            if (a[i] == b[0]) flag2 = true;
        }

        if (flag1 && flag2) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}