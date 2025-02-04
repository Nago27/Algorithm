// 자연수 N을 연속된 자연수의 합으로 나타내는 가짓수 출력
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int sum = 1, cnt = 1; // cnt = 1인 이유는 자기 자신을 더하는 경우
    int start = 1, end = 1;

    while (end != N) {
        if (sum == N) { // 답을 찾았을 경우
            cnt++;
            end++;
            sum += end;
        }

        else if (sum > N) {
            sum = sum - start;
            start++;
        }

        else { // sum < N
            end++;
            sum += end;
        }
    }
    cout << cnt << "\n";
}