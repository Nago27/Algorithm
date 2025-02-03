// N개의 수가 주어질때, 연속된 부분의 합이 M으로 나누어떨어지는 구간의 개수
// (a+b) % c = ((a % c) + (b % c)) % c , 구간 합 배열 S[i]-S[j]는 원본 배열 j+1부터 i 까지 의 합과 동일

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector <long> S (N+1,0); // 런타임 오류 신경써야함
    vector <long> C (M,0);
    long res = 0;

    cin >> S[0];
    for (int i=1; i<N; i++) { // 구간 합 배열
        int temp = 0;
        cin >> temp;
        S[i] = S[i-1] + temp;
    }
    
    for (int i=0; i< N; i++) {
        int rem = S[i] % M; // 합 배열을 M으로 나눈 나머지
        
        if (rem == 0) { // 나머지 0인 애들은 경우의수에 해당됨
            res++;
        }
        C[rem]++; // 나머지가 같은 인덱스 수 세기
    }
    
    for (int i=0; i< M; i++){
        // 경우의 수 계산 (조합)
        if(C[i] > 1){
            res = res + (C[i] * (C[i]-1) / 2);
        }
    }

    cout << res << '\n';

    return 0;
}