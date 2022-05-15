#include <iostream>
#include <map>
#include <queue>
using namespace std;

map<int, int> t;

int main() {
    int N;
    cin >> N;

    queue<int> q;
    t[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == N) break;
        if (cur > N) continue;

        if (t[cur+88] == 0) {
            q.push(cur+88);
            t[cur+88] = t[cur]+1;
        }
        if (t[cur+138] == 0) {
            q.push(cur+138);
            t[cur+138] = t[cur]+1;
        }      
    }

    if (t[N]) cout << t[N]-1 << '\n';
    else cout << "-1\n";

    return 0;
}