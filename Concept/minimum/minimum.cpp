// N개의 수와 L이 주어지고, 그 수중 최솟값을 D라고 하면 D에 저장된 수를 출력
#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, L;
    cin >> N >> L;

    deque<pair<int, int>> dq;

    for (int i=0; i < N; i++){
        int num;
        cin >> num;

        while (dq.size() && dq.back().first > num) { // 현재 수 보다 큰 값을 덱에서 제거 / .first: pair 클래스 멤버
            dq.pop_back(); 
        }
        dq.push_back({num, i});

        // 범위에서 벗어난 값은 덱에서 제거
        if(dq.front().second <= i - L) {
            dq.pop_front();
        }

        cout << dq.front().first << ' ';
    }
}