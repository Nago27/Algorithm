#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[101][101] = { false };

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int N = maps.size();
    int M = maps[0].size();

    int m_x = 0, m_y = 0;

    queue<pair<int, int> > q;
    q.push(make_pair(m_x, m_y));

    while(!q.empty()){
        int now_x, now_y;
        now_x = q.front().first;
        now_y = q.front().second;
        q.pop();
        visited[m_x][m_y] = true;

        for(int i=0; i < 4; i++){
            int x = now_x + dx[i];
            int y = now_y + dy[i];

            if(x >= 0 && y >= 0 && x < N && y < M) {
                if(maps[x][y] != 0 && !visited[x][y]){
                    visited[x][y] = true;
                    maps[x][y] = maps[now_x][now_y] + 1;
                    q.push(make_pair(x, y));
                }
            }
        }
    }
    if (maps[N-1][M-1] > 1) {
        answer = maps[N-1][M-1];
    }
    
    return answer;
}

int main(){

}