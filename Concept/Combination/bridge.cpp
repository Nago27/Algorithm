// 백준 1010번 -> 조합 점화식 사용
#include <iostream>
using namespace std;

int main() {
    int T, N, M; // N이 서쪽, M이 동쪽
    int D[31][31];

    for (int i = 0 ; i < 31; i++) { // DP 초기화
        D[i][1] = i;
        D[i][0] = 1;
        D[i][i] = 1;
    }

    for(int i = 2; i < 31; i++){
        for (int j = 1; j < i; j++){
            D[i][j] = D[i-1][j] + D[i-1][j-1]; // 조합 점화식 nCr
        }
    }

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N >> M;
        cout << D[M][N] << "\n";
    }
}