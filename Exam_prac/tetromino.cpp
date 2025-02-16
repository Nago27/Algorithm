// 정사각형 4개를 이어붙인 테르노미노를 N*M인 종이 위에 둔다고 할 때, 각 칸에 적힌 정수의 합의 최대를 구하시오.
// ㅗ 형태의 모양을 제외한 나머지는 depth=4인 dfs로 구현. ㅗ 형태는 가운데에서 상하좌우 따져야 할 듯
#include <iostream>
using namespace std;

int N, M, result = 0;  // N: 세로, M: 가로
int paper[501][501];
bool visited[501][501] = { false };
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void DFS(int x, int y, int depth, int sum){
    if (depth == 4){
        result = max(result, sum);
        return;
    }

    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || ny < 1 || nx > N || ny > M || visited[nx][ny]) continue;

        // 백트래킹으로 탐색
        visited[nx][ny] = true;
        DFS(nx, ny, depth+1, sum + paper[nx][ny]);
        visited[nx][ny] = false;
    }

    // ㅗ, ㅓ, ㅏ , ㅜ 형태 예외 처리 (DFS로 구현을 못함)

    if(x-1 >= 1 && x+1 <= N && y+1 <= M) { // ㅗ 모양
        result = max(result, paper[x-1][y]+paper[x][y]+paper[x+1][y]+paper[x][y+1]);
    }

    if(x-1 >= 1 && x+1 <= N && y-1 >= 1) { // ㅜ 모양
        result = max(result, paper[x-1][y]+paper[x][y]+paper[x+1][y]+paper[x][y-1]);
    }

    if(x-1 >= 1 && y+1 <= M && y-1 >= 1) { // ㅓ 모양
        result = max(result, paper[x-1][y]+paper[x][y]+paper[x][y+1]+paper[x][y-1]);
    }

    if(x+1 <= N && y+1 <= M && y-1 >= 1) { // ㅏ 모양
        result = max(result, paper[x+1][y]+paper[x][y]+paper[x][y+1]+paper[x][y-1]);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++){
            cin >> paper[i][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++){
            visited[i][j] = true;
            DFS(i, j, 1, paper[i][j]);
            visited[i][j] = false;
        }
    }

    cout << result;
}