// 버블 정렬의 swap이 한 번도 일어나지 않은 루프가 언제인지 출력 / 안쪽 루프에서 swap이 안 일어남
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector< pair<int,int> > A(N); 

    for (int i=0; i < N; i++) {
        cin >> A[i].first; // 정렬 후 인덱스 값 비교
        A[i].second = i; // 정렬 전 인덱스 값 비교
    }

    sort(A.begin(), A.end()); // 배열 정렬 O(nlogn)

    int max = 0;

    for (int i=0; i < N; i++){
        if(max < A[i].second - i){
            max = A[i].second - i;
        }
    }

    cout << max + 1 << "\n"; // swap이 일어나지 않는 반복문이 한번 더 실행된 경우까지 +1
}