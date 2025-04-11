// 백준 1992번 : 쿼드 트리
#include <iostream>
#include <string>
using namespace std;

string map[64]; // 입력시 공백이 없으므로 문자열 형태로 받아야 함.

void QuadTree(int x, int y, int len) {
    char cur = map[x][y];

    for(int i = x; i < x + len; i++){
        for(int j = y; j < y + len; j++){
            if(cur != map[i][j]){
                cout << '(';
                QuadTree(x, y, len / 2); // 좌상단
                QuadTree(x, y + len/2, len / 2); // 우상단
                QuadTree(x + len/2, y, len / 2);// 좌하단
                QuadTree(x + len/2, y + len/2, len / 2);// 우하단
                cout << ')';
                return;
            }
        }
    }

    cout << cur;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> map[i];
    }

    QuadTree(0, 0, N);
    return 0;
}