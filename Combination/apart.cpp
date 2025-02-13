// 백준 2775
#include <iostream>
using namespace std;

int main() {
    // D[a][b] = (D[a-1][1] + ... + D[a-1][b-1])=D[a][b-1] + D[a-1][b]

    int T, k, n;
    int D[15][15];

    for (int i=0; i < 15; i++){ // DP 초기화
        D[i][1] = 1; // 각 층에 1호실만은 경우의 수 1
        D[0][i] = i; // 0층에 i호의 수는 i
    }

    for (int i = 1; i < 15; i++){
        for(int j = 2; j < 15; j++){
            D[i][j] = D[i][j-1] + D[i-1][j]; // 점화식 도출
        }
    }

    cin >> T;
    
    for (int i = 0; i < T; i++){
        cin >> k >> n;
        cout << D[k][n] << "\n";
    }
}