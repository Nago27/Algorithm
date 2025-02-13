#include <iostream>
using namespace std;

int main(){
    int N, K;
    int D[1001][1001];

    cin >> N >> K;

    for (int i=0; i <= N; i++){ // DP 테이블 초기화
        D[i][1] = i; // i개 중 1개를 뽑는 경우의 수
        D[i][0] = 1; // i개 중 하나도 뽑지 않는 경우의 수
        D[i][i] = 1; // i개 중 i개를 뽑는 경우의 수
    }

    for (int i = 2; i <= N; i++){
        for(int j = 1; j < i; j++){
            D[i][j] = D[i-1][j] + D[i-1][j-1]; // 조합 점화식
            D[i][j] = D[i][j] % 10007; // 모듈러 연산
        }
    }

    cout << D[N][K] << "\n";
}