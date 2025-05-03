// 백준 1652번
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, row = 0, col = 0, check = 0;
    char map[101][101];

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
           cin >> map[i][j];
        }
    }

    // 가로로 누울 자리
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == '.') check++;
            else check = 0;

            if(check == 2){
                row++;
            }
        }
        check = 0;
    }

    check = 0;
    // 세로로 누울 자리
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[j][i] == '.') check++;
            else check = 0;

            if(check == 2){
                col++;
            }
        }
        check = 0;
    }

    cout << row << " " << col << "\n";
}