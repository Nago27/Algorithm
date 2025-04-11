// 방향 없는 그래프가 주어졌을 때, 연결 요소의 개수를 구하시오 (노드 개수:N, 에지 개수: M)
#include <iostream>
#include <vector>
using namespace std;

static vector< vector <int> > A;
static vector<bool> visited;
void DFS(int v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    A.resize(N + 1);
    visited = vector<bool>(N + 1, false);

    for(int i = 0; i < M; i++){ // 인접 리스트 A에 그래프 데이터 저장
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    int cnt = 0;
    for(int i = 1; i < N+1; i++){
        if(!visited[i]){ // 방문하지 않은 노드가 없을때까지 반복
            cnt++;
            DFS(i);
        }
    }

    cout << cnt << "\n";
}

void DFS(int v)
{
    if(visited[v]){
        return;
    }

    visited[v] = true;

    for(int i : A[v]){
        if(visited[i] == false){ // 연결된 노드 중 방문하지 않은 노드만 탐색
            DFS(i);
        }
    }
}
