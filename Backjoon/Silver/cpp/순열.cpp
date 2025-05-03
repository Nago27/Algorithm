// 백준 10972 다음 순열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    int num[10000] = {0, };
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num[i];
    }

    if(next_permutation(num, num + N)){ // next_permutation으로 시작 컨테이너를 입력받은 순열로 시작
        for(int i = 0; i < N; i++){
            cout << num[i] << " ";
        }
    }
    else cout << "-1" << "\n";

    return 0;
}