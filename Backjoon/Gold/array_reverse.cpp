// 백준 16926번 배열 돌리기(1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int arr[301][301];
    int N, M, R;

    cin >> N >> M >> R;
    
    for(int i = 0; i < N; i++) { // 배열 입력
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    int rotate = min(N,M) / 2;

    while(R--) {
        for(int r = 0; r < rotate; r++){
            int temp = arr[r][r];
            int sx = r, sy = r, ex = N - r -1, ey = M - r -1;

            // 윗줄 : 왼쪽 방향
            for (int i = r; i < ey; i++) arr[r][i] = arr[r][i+1];
            
            // 오른쪽 열 : 위 방향
            for (int i = r; i < ex; i++) arr[i][ey] = arr[i+1][ey];

            // 아랫줄 : 오른쪽 방향
            for (int i = ey; i > r; i--) arr[ex][i] = arr[ex][i-1];

            // 왼쪽 열 : 아래 방향
            for (int i = ex; i > r; i--) arr[i][r] = arr[i-1][r];

            // 비워진 칸 채우기
            arr[r+1][r] = temp;
        }
    }

    for(int i = 0; i < N; i++) { // 배열 입력
        for(int j = 0; j < M; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

}