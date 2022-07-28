#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int n, a, b;
        cin >> n >> a >> b;

        int remain_time = max(a, n-b);
        cout << "The scoreboard was frozen with " << remain_time << " minute";
        if (remain_time == 1) cout << " remaining.\n";
        else cout << "s remaining.\n";
    }

    return 0;
}
