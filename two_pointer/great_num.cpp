// N개의 수에서 다른 두 수의 합으로 표현되는 좋은 수가 몇 개인지 구하는 문제
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
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        long K = arr[i];
        int left = 0;
        int right = N - 1;

        while (left < right) {
            if (arr[left]+arr[right] == K) {
                if (left != i && right != i) {
                    cnt++;
                    break;
                }
                else if (left == i) {
                    left++;
                }
                else { // right == i
                    right--;
                }
            }
            else if (arr[left]+arr[right] < K) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    /* 이진트리 함수를 이용한 코드 단축
    for (int i = 0; i < N; i++) { 
        for (int j = i+1; j < N; j++) {
            if (arr[i] == arr[j]) {
                continue;
            }
            if (binary_search(arr.begin(), arr.end(), arr[i]+arr[j])) {
                cnt++;
            }
        }
    }
    */
    cout << cnt << "\n";
}