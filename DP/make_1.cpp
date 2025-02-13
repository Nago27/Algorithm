#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static int N;
static vector<int> D; // 1로 만드는데 최소 연산 횟수 DP 테이블

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    D.resize(N+1);
    D[1] = 0;

    for(int i = 2; i <= N; i++){
        D[i] = D[i-1] + 1; // 1을 빼는 연산
        if(i%2 == 0){
            D[i] = min(D[i], D[i/2] + 1); // 2로 나누어 떨어지는 연산
        }
        if (i%3 == 0){
            D[i] = min(D[i], D[i/3] + 1); // 3로 나우어 떨어지는 연산
        }
    }

    cout << D[N];
}