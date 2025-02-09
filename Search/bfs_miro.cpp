// 백준 2178번 미로 탐색 (너비 우선 탐색)
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

static int Map[101][101]; // 자표 입력 배열
static bool visited[101][101] = { false }; // 방문 기록
static int dx[4] = {-1, 1, 0, 0}; // 상하좌우 탐색 배열
static int dy[4] = {0, 0, -1, 1};
static int N, M;
void BFS (int map_x, int map_y);

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++){ // 좌표 데이터 입력 받기
        string s;
        cin >> s;
        for (int j = 0; j < M; j++){
            Map[i][j] = s[j] - '0';
        }
    }

    BFS(0, 0);
    cout << Map[N-1][M-1] << "\n";
}

void BFS(int map_x, int map_y){ // 너비 우선 탐색 구현
    queue<pair<int, int> > Myqueue;
    Myqueue.push(make_pair(map_x, map_y));

    while(!Myqueue.empty()){
        int now_x, now_y;
        now_x = Myqueue.front().first;
        now_y = Myqueue.front().second;
        Myqueue.pop(); // 방문한 좌표는 큐에서 제거
        visited[map_x][map_y] = true;

        for(int i = 0; i < 4; i++) { // 현재 좌표에서 상하좌우 인접한 좌표 탐색
            int x = now_x + dx[i];
            int y = now_y + dy[i];

            if(x >= 0 && y >= 0 && x < N && y < M){ // 인접한 좌표가 존재, 이동 가능한지
                if(Map[x][y] != 0 && !visited[x][y]){ // 탐색한 좌표를 방문했었는지
                    visited[x][y] = true;
                    Map[x][y] = Map[now_x][now_y] + 1; // 해당 인접 좌표는 + 1
                    Myqueue.push(make_pair(x,y));
                }
            }
        }
    }

}
