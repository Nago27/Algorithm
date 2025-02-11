#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());  // O(logn)

    cin >> M;
    for (int i = 0; i < M; i++){
        bool find = false;
        int target;
        cin >> target;
        
        int s = 0;
        int e = A.size() - 1;
        while (s <= e){
            int mid = (s + e) / 2;

            if(A[mid] > target){
                e = mid - 1;
            }
            else if (A[mid] < target){
                s = mid + 1;
            }
            else {
                find = true;
                break;
            }
        }
        if (find) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}