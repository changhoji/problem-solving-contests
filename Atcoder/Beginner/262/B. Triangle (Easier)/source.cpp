#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, pair<int, int>> connected;
struct t {
    int a, b, c;

    void s() {
        int num[3] = {a, b, c};
        sort(num, num+3);
        a = num[0];
        b = num[1];
        c = num[2];
    }
};

vector<int> edges[101];

int main() {
    int N, M;
    cin >> N >> M;

    int U, V;
    for (int i = 0; i < M; i++) {
        cin >> U >> V;
        edges[U].push_back(V);
        edges[V].push_back(U);
    }

    for (int i = 1; i <= N; i++) {
        sort(edges[i].begin(), edges[i].end());
    }

    set<connected> ans;

    for (int a = 1; a <= N-2; a++) {
        for (auto b: edges[a]) {
            for (auto c: edges[b]) {
                if (binary_search(edges[a].begin(), edges[a].end(), c)) {
                    t temp = {a, b, c};
                    temp.s();
                    connected term = make_pair(temp.a, make_pair(temp.b, temp.c));
                    ans.insert(term);
                }
            }
        }
    }

    cout << ans.size() << '\n';

    return 0;
}
