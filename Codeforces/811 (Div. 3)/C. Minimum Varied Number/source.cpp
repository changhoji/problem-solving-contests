#include <iostream>
#include <algorithm>
using namespace std;

int ans = 987654321;

void backtracking(int s, int start, int num, int sum);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int s;
        cin >> s;

        ans = 978654321;
        backtracking(s, 1, 0, 0);
        cout << ans << '\n';
    }

    return 0;
}

void backtracking(int s, int start, int num, int sum) {
    if (sum > s) return;
    if (sum == s) {
        ans = min(ans, num);
        return;
    }

    for (int i = start; i <= 9; i++) {
        backtracking(s, i+1, num*10+i, sum+i);
    }
}