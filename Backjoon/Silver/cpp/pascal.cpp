// 백준 15489번 
// R번째 줄, C번째 수를 위 꼭짓점으로 하는 한 변이 포함하는 수의 개수가 W인 정삼각형과 그 내부의 있는 수들의 합 출력
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int dp[31][31];

    int R, C, W;
    int cnt = 0;
    cin >> R >> C >> W;

    for(int i = 1; i <= 30; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1 || j == i){ // 양끝은 전부 1로 처리
                dp[i][j] = 1;
            }   
            else { // 조합식
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }

    for(int i = 0; i < W; i++){
        for(int j = 0; j <= i; j++){
            cnt += dp[R+i][C+j];
        }
    }

    cout << cnt << "\n";
}