#include <iostream>
using namespace std;

int main() {
    int Y;
    cin >> Y;

    while ((Y%4) != 2) Y++;

    cout << Y << '\n';

    return 0;
}
