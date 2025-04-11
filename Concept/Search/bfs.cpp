// BFS 와 DFS를 구분지어 구현
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue> // DFS 구현
using namespace std;

static vector < vector<int> > A; // 인접 리스트
static vector <bool> visited; // 방문 기록 리스트

void DFS(int node);
void BFS(int node);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, start;
    cin >> N >> M >> start;
    A.resize(N+1);

    for (int i = 0 ; i < M; i++){
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    for (int i = 1; i <= N; i++){
        sort(A[i].begin(), A[i].end()); // 노드 번호가 작은 것부터 먼저 방문하고자 정렬
    }

    visited = vector<bool> (N+1, false);
    DFS(start);
    cout << "\n";
    fill(visited.begin(), visited.end(), false); // 방문 리스트 초기화
    BFS(start);
    cout << "\n";
}

void DFS(int node) { // 깊이 우선 탐색 (재귀함수 활용)
    cout << node << " ";
    visited[node] = true;

    for (int i : A[node]){
        if(!visited[i]){
            DFS(i);
        }
    }

}

void BFS(int node){ // 너비 우선 탐색 (queue 활용)
    visited[node] = true;
    queue<int> bfs_queue;
    bfs_queue.push(node);

    while(!bfs_queue.empty()){
        int now = bfs_queue.front();
        bfs_queue.pop(); // 가져온 노드는 큐에서 제거
        cout << now << " ";
        for (int i : A[now]){
            if(!visited[i]){
                visited[i] = true;
                bfs_queue.push(i);
            }
        }
    }
}
