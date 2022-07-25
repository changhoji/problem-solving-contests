#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;

        if (n%2) {
            cout << "1 ";
            for (int i = 0; i < n/2; i++) {
                cout << i*2+3 << " " << i*2+2 << " ";
            }
            cout << '\n';
        }
        else {
            for (int i = 0; i < n/2; i++) {
                cout << i*2+2 << " " << i*2+1 << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}