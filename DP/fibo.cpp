#include <iostream>
using namespace std;

int fibo[41][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    
    fibo[0][0] = 1;
    fibo[1][1] = 1;
    
    for(int i = 2; i <= 40; i++){ // count에서 dp 알고리즘 적용
        fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
        fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
    }

    while(T--) {
        int N;
        cin >> N;
        
        cout << fibo[N][0] << ' ' << fibo[N][1] << '\n';
    }
}