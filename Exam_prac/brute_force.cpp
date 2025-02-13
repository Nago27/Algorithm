// 모든 경우의 수를 고려하는 브루트 포스 알고리즘
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string board[50];

string WB[8] = { // white 부터 시작하는 8*8
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string BW[8] = { // black 부터 시작하는 8*8
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int WB_check(int x, int y){
    int cnt = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(board[x+i][y+j] != WB[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int BW_check(int x, int y){
    int cnt = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(board[x+i][y+j] != BW[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    int res = 2000;
    cin >> N >> M;  

    for (int i = 0; i < N; i++){
        cin >> board[i];
    }

    for (int i = 0; i+8 <= N; i++){
        for (int j = 0; j+8 <= M; j++){
            int temp = min(WB_check(i,j), BW_check(i,j));
            if (temp < res){
                res = temp;
            }
        }
    }

    cout << res << "\n";
}