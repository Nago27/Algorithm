// 재료의 개수 N이 주어졌을때, 고유한 번호들의 재료들이 M이 되기 위한 경우의 수를 출력
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;
    cin >> M;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int cnt = 0;
    int i = 0, j = N-1;

    while (i < j) {
       if (A[i] + A[j] == M) {
           cnt++;
           i++;
           j--;
       }
       else if (A[i] + A[j] < M) {
           i++;
       }
       else { // A[i] + A[j] > M
           j--;
       }
    }
    
    cout << cnt << "\n";
}