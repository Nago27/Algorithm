#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v1;
vector<int> v2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    // 첫 번째 경주
    for (int i = 1; i <= N; i++){
        int x1;
        cin >> x1;
        v1.insert(v1.begin()+(x1 - 1), i);
    }
    // M명까지만 남기기
    while (v1.size() > M) {
        v1.pop_back();
    }

    // 두번째 경주
    for (int i = 1; i <= M; i++){
        int x2;
        cin >> x2;
        v2.insert(v2.begin()+(x2 - 1), v1.back()); // M등부터 역순으로
        v1.pop_back();
    }

    // 3등까지만 남기기
    while (v2.size() > 3){
        v2.pop_back();
    }

    for(int i = 0; i < 3; i++){
        cout << v2[i] << "\n";
    }
}