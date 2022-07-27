#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll constant = 1;

vector<double> terms;

void printVec();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int cmd;
        cin >> cmd;

        ll a, b;
        if (cmd == 1) {
            cin >> a >> b;
            if (a == 0) {
                if (b > 0) continue;
                else if (b == 0) constant = 0;
                else constant = -constant;
            }
            terms.push_back(-(double)b/a);
            if (a < 0) constant = -constant;
        }
        else {
            sort(terms.begin(), terms.end());
            //printVec();
            cin >> a;

            int idx = lower_bound(terms.begin(), terms.end(), a) - terms.begin();
            if (terms[idx] == a || constant == 0) {
                cout << "0\n";
                continue;
            }
            int minus;

            if (idx >= terms.size()) minus = 0;
            else minus = terms.size() - idx;

            //printf("idx = %d, minus = %d\n", idx, minus);

            if ((minus % 2 && constant > 0) || (!(minus % 2) && constant < 0)) cout << "-\n";
            else cout << "+\n";
        }
    }

    return 0;
}

void printVec() {
    printf("vec: ");
    for (auto i: terms) {
        cout << i << " ";
    }
    cout << '\n';
}