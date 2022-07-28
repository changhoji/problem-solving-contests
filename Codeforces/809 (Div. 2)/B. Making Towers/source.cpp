#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int c[100000];
int dp[100001][2]; //dp[num][0] / dp[num][1]: num의 idx의 마지막이 짝수번째 / 홀수번째

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);

    

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        memset(dp, 0, sizeof(dp));    
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int c;
            cin >> c;

            dp[c][i%2] = max(dp[c][(i%2+1)%2]+1, dp[c][i%2]);
        }

        for (int num = 1; num <= n ;num++) {
            cout << max(dp[num][0], dp[num][1]) << " ";

        }        
        cout << "\n";
    }

    return 0;
}
