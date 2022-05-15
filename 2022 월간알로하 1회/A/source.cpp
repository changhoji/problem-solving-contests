#include <iostream>
using namespace std;

int arr[] = {0, 1, 2, 0, 1, 3, 0, 1, 4, 0, 1, 3, 0, 1, 2, 2};

int main() {
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int x;
        cin >> x;

        cout << arr[(x-1)%16] << '\n';
    }

    return 0;
}