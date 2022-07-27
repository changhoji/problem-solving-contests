#include <iostream> 
#include <algorithm>
using namespace std;

int a[100001];
int deg[100001];
pair<int, int> p[100000];

int main() {
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            deg[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            cin >> p[i].first >> p[i].second;
            deg[p[i].first]++;
            deg[p[i].second]++;
        }

        int ans = 1000000000;

        if (!(m%2)) ans = 0;
        else {
            for (int i = 1; i <= n; i++) { //한명만 참석 안하게 하려면 deg가 홀수인 사람을 안보내면 됨
               if (deg[i]%2) ans = min(ans, a[i]);
            }
            for (int i = 0; i < m; i++) { //deg가 짝수인 이웃한 정점 두개를 빼면 케이크 개수가 홀수개로 빠짐
                if (!(deg[p[i].first]%2) && !(deg[p[i].second]%2)) 
                    ans = min(ans, a[p[i].first] + a[p[i].second]);
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}
