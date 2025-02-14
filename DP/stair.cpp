// 백준 2579번
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> score(N);
    vector<int> dp(N+1, 0);

    for(int i = 0; i < N; i++){
        cin >> score[i];
    }

    dp[0] = score[0];
    dp[1] = score[0] + score[1];
    dp[2] = max(score[0]+score[2], score[1]+score[2]);

    for(int i = 3; i <= N; i++){
        dp[i] = max(dp[i-3] + score[i-1] + score[i], dp[i-2] + score[i]);
    }

    cout << dp[N-1] << "\n";
}