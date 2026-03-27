// 백준 11053번: 긴 부분수열 찾기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int A[N];
    vector<int> D(N, 1); 

    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                D[i] = max(D[i], D[j] + 1);
            }
        }
    }
   
    cout << *max_element(D.begin(), D.end());
}