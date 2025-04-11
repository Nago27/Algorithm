// N개의 동전 종류가 주어질 때, K원을 만드는 데 필요한 동전의 개수의 최솟값
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> coin(N);

    for (int i = 0; i < N; i++){
        cin >> coin[i];
    }

    int res;
    for(int i = N-1; i >= 0; i--){ // 가장 큰 단위가 항상 작은 단위의 배수라서 작은 단위 동전들은 다른 해가 나올 수 없음.
        res += (K / coin[i]);
        K %= coin[i];
    }

    cout << res << "\n";
}