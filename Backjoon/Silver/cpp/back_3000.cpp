// 백준 3000번 : 직각 삼각형
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int X[100001];
int Y[100001];

pair<int, int> map[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i=0; i < N; i++) {
        int in_x, in_y;
        cin >> in_x >> in_y;
        map[i] = {in_x, in_y};

        X[in_x]++;
        Y[in_y]++;
    }

    // 좌표 한개를 설정해서 같은 x or y를 공유하는 좌표 찾기
    ll cnt = 0;
    for (int i=0; i < N; i++){
        cnt += (X[map[i].first] - 1) * (Y[map[i].second] - 1);
    }

    cout << cnt;
}