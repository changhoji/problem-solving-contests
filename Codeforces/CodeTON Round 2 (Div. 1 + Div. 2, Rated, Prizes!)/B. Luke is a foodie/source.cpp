#include <iostream>
#include <algorithm>
using namespace std;

int abs(int x) { return (x > 0) ? x : -x; }

int a[200000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n, x;
        cin >> n >> x;

        int max_v = 0;
        int min_v = 1000000001;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        max_v = max(max_v, a[0]);
        min_v = min(min_v, a[0]);

        for (int idx = 1; idx < n; idx++) {
            if (max(abs(a[idx]-min_v), abs(a[idx]-max_v)) > 2*x) {
                ans++;
                max_v = a[idx];
                min_v = a[idx];
            }
            else {
                max_v = max(max_v, a[idx]);
                min_v = min(min_v, a[idx]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
