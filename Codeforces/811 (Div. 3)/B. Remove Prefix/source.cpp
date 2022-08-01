#include <iostream>
#include <cstring>
using namespace std;

int a[200000];
bool exist[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;

        memset(exist, false, sizeof(exist));
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int i;
        for (i = n-1; i >= 0; i--) {
            if (exist[a[i]]) break;
            exist[a[i]] = true;
        }

        cout << i+1 << '\n';
    }    

    return 0;
}
