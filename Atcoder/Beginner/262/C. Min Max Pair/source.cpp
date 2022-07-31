#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;

    vector<int> v(N+1);
    v.push_back(0);

    int same = 0;
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        if (i == v[i]) same++;
    }

    ll ans = 0;
    int used_same = 0;

    for (int i = 1; i <= N; i++) {
        if (i == v[i]) {
            used_same++;
            ans += same - used_same;
            continue;
        }
        if (i < v[i]) continue;
        if (v[v[i]] == i) ans++;
    }

    cout << ans << '\n';

    return 0;
}

