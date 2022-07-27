#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int d_row[] = { 1, 0, -1, 0 };
int d_col[] = { 0, 1, 0, -1 };

int N, M, S;
char map[50][50];
int exist[26] = { 0,};

struct pos {
    int row, col;
};

pair<string, pos> bfs(pos from, char target);

int main() {
    cin >> N >> M >> S;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            exist[map[i][j]-'a']++;
        }
    }

    int need[26] = { 0,};

    string str;
    cin >> str;

    for (auto c: str) {
        need[c-'a']++;
    }

    int can = 2500;
    for (int i = 0; i < 26; i++) {
        if (need[i]) can = min(can, exist[i]/need[i]);
    }

    pos now = {0, 0};
    for (int i = 0; i < S*can; i++) {
        auto p = bfs(now, str[i%S]);
        now = p.second;
        cout << p.first << 'P';
    }
    cout << '\n';

    return 0;
}

pair<string, pos> bfs(pos from, char target) {
    bool visited[50][50] = { false,};
    queue<string, pos> q;
    string str(0);

    q.push(make_pair(str, from));

    while (1) {
        auto cur = q.front();
        q.pop();

        if (map[cur.])
    }
}