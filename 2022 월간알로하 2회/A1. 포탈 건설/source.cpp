#include <iostream>
#include <vector>
using namespace std;

vector<int> neighbors[1000000];
int cost[1000000];
int par[1000000];

int find(int a);
void union_(int a, int b);

int main() {
    int N, M;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        par[i] = i;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }

    

}

int find(int a) {
    if (par[a] == a) return a;
    else return par[a] = find(par[a]);
}

void union_(int a, int b) {
    int aa = find(a);
    int bb = find(b);
    if (aa < bb) par[bb] = aa;
    else par[aa] = bb;
}