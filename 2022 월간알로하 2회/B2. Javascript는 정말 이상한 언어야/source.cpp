#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string arr[200000];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr[i] = to_string(num);
    }

    sort(arr, arr+N);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}
