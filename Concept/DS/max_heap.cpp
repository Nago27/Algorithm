#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

priority_queue<int> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if(x > 0) {
            arr.push(x);
        }
        else {
            if(!arr.empty()) {
                cout << arr.top() << "\n";
                arr.pop();
            }
            else {
                cout << 0 << "\n";
            }
        }
    }
}