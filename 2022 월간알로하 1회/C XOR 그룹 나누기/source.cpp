#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backTracking(int cnt);
int calculate();

int N;
int answer = 0;

int group[18] = { 0,};
int feat[18];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> feat[i];
    }

    backTracking(0);

    cout << answer << '\n';
    
    return 0;
}

void backTracking(int cnt) {
    //printf("cnt = %d\n", cnt);
    if (cnt == N/3*2) {
        answer = max(answer, calculate());
        //printf("answer = %d\n", answer);
        return;
    }

    if (cnt < N/3) {
        for (int i = 0; i < N; i++) {
            if (group[i] != 0) continue;

            group[i] = 1;
            backTracking(cnt+1);
            group[i] = 0;
        }
    }
    else {
        vector<int> group1;
        for (int i = 0; i < N; i++) {
            if (group[i] == 1) group1.push_back(feat[i]);
        }
        int val = group1[0];
        for (int i = 1; i < group1.size(); i++) {
            val ^= group1[i];
        }

        if (val < answer) return;

        for (int i = 0; i < N; i++) {
            if (group[i] != 0) continue;

            group[i] = 2;
            backTracking(cnt+1);
            group[i] = 0;
        }
    }
}

int calculate() {
    vector<int> v[3];
    for (int i = 0; i < N; i++) {
        if (group[i] == 1) v[0].push_back(feat[i]);
        else if (group[i] == 2) v[1].push_back(feat[i]);
        else v[2].push_back(feat[i]);
    }

    int res[3];
    for (int i = 0; i < 3; i++) {
        res[i] = v[i][0];
        for (int j = 1; j < v[i].size(); j++) {
            res[i] = res[i] ^ v[i][j];
        }
    }

    return min(res[0], min(res[1], res[2]));
}