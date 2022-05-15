#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    int N, P, Q, K;
    cin >> N;

    vector<ll> h(N);

    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    cin >> P >> Q >> K;

    int answer = 1;

    int left = 1, right = 110000;
    while (left <= right) {
        int mid = (left + right) / 2;
    
        ll balance = K;
        for (auto i: h) {
            if (i > mid) { //목표보다 크면 자르기
                balance += (i-mid)*P;
            }
            else if (i < mid) {
                balance -= (mid-i)*Q;
            }
        }

        if (balance >= 0) {
            answer = max(answer, mid);
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }

    cout << answer << '\n';

    return 0;
}