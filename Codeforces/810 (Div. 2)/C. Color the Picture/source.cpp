#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool is_able(int n, int m, int k, vector<int> a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    vector<int> a; //a, used
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n, m, k;
        cin >> n >> m >> k;

        a.clear();
        for (int i = 0; i < k; i++) {
            int num;
            cin >> num;
            a.push_back(num);
        }
        sort(a.begin(), a.end(), greater<int>());

        bool ans;
        if (is_able(n, m, k, a) || is_able(m, n, k, a)) ans = true;
        else ans = false;


        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}

bool is_able(int n, int m, int k, vector<int> a) {
    ll done = 0;
    bool exist_gtt_3 = false;

    for (int i = 0; i < k; i++) {
        if (a[i] / n >= 3) exist_gtt_3 = true;
        if (a[i] / n >= 2) done += a[i]/n;
    }

    if (!(m%2)) {
        if (done >= m) return true;
    }
    else {
        if (done >= m && exist_gtt_3) return true;
    }

    return false;
}
