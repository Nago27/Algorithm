// 백준 2630번 : 색종이 만들기 / 하얀색: 0, 파란색: 1
#include <iostream>
#include <vector>
using namespace std;

int N; // 정사각형 한 변의 길이
int paper[129][129];
int w_cnt = 0, b_cnt = 0;

void merge(int x, int y, int len) {
    int cur = paper[x][y];
    bool check = true;

    for(int i = x; i < x+len; i++){
        for(int j = y; j < y+len; j++){
            if(paper[i][j] != cur){ // 하나라도 같은 색이 아니라면,
                check = false;
                break;
            }
        }
    }

    if(!check) {
        merge(x, y, len / 2); // 좌상단
        merge(x, y + len/2, len / 2); // 우상단
        merge(x + len/2, y, len / 2);// 좌하단
        merge(x + len/2, y + len/2, len / 2);// 우하단
    }
    else { // 해당 정사각형 내 색이 모두 동일할 경우
        if (cur == 0) // 하얀색
            w_cnt++;
        else          // 
            b_cnt++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> paper[i][j];
        }
    }

    merge(1, 1, N);

    cout << w_cnt << "\n" << b_cnt << "\n";
}