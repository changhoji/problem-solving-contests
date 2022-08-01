#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        vector<pair<int, int>> time;

        int n, H, M;
        cin >> n >> H >> M;
        time.push_back(make_pair(H, M));

        for (int i = 0; i < n; i++) {
            int h, m;
            cin >> h >> m;
            time.push_back(make_pair(h, m));
        }

        sort(time.begin(), time.end());
        time.push_back(time[0]);

        int idx = 0;
        for (; idx < n; idx++) {
            if (time[idx].first == H && time[idx].second == M) break;
        }

        pair<int, int> ans = make_pair(time[idx+1].first - time[idx].first, time[idx+1].second - time[idx].second);
        if (ans.second < 0) {
            ans.first--;
            ans.second += 60;
        }
        if (ans.first < 0) ans.first += 24;

        cout << ans.first << " " << ans.second << '\n';
        
    }
    return 0;
}