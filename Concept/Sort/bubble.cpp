// sort()를 쓰지 않고 수 정렬
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N, 0);

    for (int i=0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i=0;i < N; i++){
        for (int j=0; j < N-1; j++){
            if (arr[j] > arr[j+1]){  // swap 연산
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (int i=0; i < N; i++){
        cout << arr[i] << "\n";
    }
}