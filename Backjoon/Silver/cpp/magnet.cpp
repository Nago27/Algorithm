// 백준 32931번 : 자석놀이
#include <iostream>
#include <algorithm>
using namespace std;

long long dp[2]; // 점화식
int cards[2][200000];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    // 카드값 입력
    for (int i=0; i<2; i++) {
        for(int j=0; j<N; j++) {
            cin >> cards[i][j];
        }
    }

    dp[0] = cards[0][0] + max(cards[1][0], 0); // 첫 열 위
    dp[1] = cards[0][0] + cards[1][0]; // 첫 열 아래

    for (int i=1; i<N; i++) {
        long long ndp0 = max(dp[0] + cards[0][i] + max(0, cards[1][i]), dp[1] + cards[0][i] + cards[1][i]);
        long long ndp1 = max(dp[1] + cards[1][i] + max(0, cards[0][i]), dp[0] + cards[0][i] + cards[1][i]);

        dp[0] = ndp0;
        dp[1] = ndp1;
    }

    cout << dp[1];
}