#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;

    int left = 0;
    int right = 724637681160;

    int ans;

    while (left <= right) {
        int mid = (left + right) / 2; //mid: mid��ŭ 138�� ���� �ִ���

        if (138*mid < N) { //���� ������
            if ((N-138*mid) % 88 == 0) {
                mid = left+1;
                ans = 
            }
        }

    }


}