// 사전에 N개의 'a'와 M개의 'z'로 이루어질 때 k번째 문자열
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    long D[202][202];

    cin >> N >> M >> K;

    for(int i = 0; i <= 200; i++){ // DP 초기화, D[남은 문자 개수][남은 z개수]
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                D[i][j] = 1; 
            }
            else {
                D[i][j] = D[i-1][j] + D[i-1][j-1]; // 조합 점화식

                if(D[i][j] > 1000000000) { // K 범위 넘어가면 범위 최대값 저장
                    D[i][j] = 1000000001;
                }
            }
        }
    }

    if(D[N + M][M] < K){ // 주어진 자릿수로 만들 수 없다면
        cout << "-1";
    }
    else {  // 현재 자리를 a로 선택하여 남은 문자로 경우의수를 구함
        while(!(N == 0 && M == 0)){
            if(D[N-1 + M][M] >= K) { // a를 선택할때 남은 문자로 만들 수 있는 경우의 수가 K보다 크면
                cout << "a";
                N--;
            }   
            else { // 모든 경우의 수가 K보다 작다면
                cout << "z";
                K = K - D[N-1 + M][M];
                M--;
            }
        }
    }

}