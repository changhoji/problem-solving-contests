#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int x, y;
        cin >> x >> y;

        if (x*x-4*y > 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}