#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

int h[100001];
ll dp[100001][2]; //dp[i][1]: i번째까지 보면서 한번 건너뜀 / 안건너뜀

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        memset(dp, 0, sizeof(dp));

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> h[i];

        //n & 1 : 1번째 비트가 1이면 (홀수면) 1이 됨. 0이면 0이 됨.
        if (n & 1) {
            ll sum = 0;
            for (int idx = 2; idx <= n-1; idx += 2) {
                //printf("+= %d\n", max((h[idx-1], h[idx+1]) + 1 - h[idx], 0));
                sum += max(max(h[idx-1], h[idx+1]) + 1 - h[idx], 0);
            }   
            cout << sum << '\n';
        }
        else {
            dp[2][0] = max(max(h[1], h[3]) + 1 - h[2], 0);
            dp[2][1] = 0;
            //printf("dp[%d][0] = %lld, dp[%d][1] = %lld\n", 2, dp[2][0], 2, dp[2][1]);
            for (int idx = 3; idx <= n-1; idx++) {
                if (idx & 1)
                    dp[idx][0] = dp[idx-1][0];
                else
                    dp[idx][0] = dp[idx-2][0] + max(max(h[idx-1], h[idx+1]) + 1 - h[idx], 0);
                
                if (idx & 1)
                    dp[idx][1] = min(dp[idx-3][0], dp[idx-2][1]) + max(max(h[idx-1], h[idx+1]) + 1 - h[idx], 0);
                else
                    dp[idx][1] = dp[idx-1][1];

                //printf("dp[%d][0] = %lld, dp[%d][1] = %lld\n", idx, dp[idx][0], idx, dp[idx][1]);
            }
            cout << min(dp[n-1][1], dp[n-1][0]) << '\n';
        }
    }

    return 0;
}

