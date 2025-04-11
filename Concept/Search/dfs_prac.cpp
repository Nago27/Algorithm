// dfs연습. 백준 13023번
// depth가 5가 되는 경우가 생기면 1 출력
#include <iostream>
#include <vector>
using namespace std;

static vector< vector<int> > A;
static vector<bool> visited;
static bool arrive_5;
void DFS(int node, int depth);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    arrive_5 = false;
    cin >> N >> M;
    A.resize(N);
    visited = vector<bool> (N, false);

    for (int i = 0; i < M; i++){
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    for (int i = 0; i < N; i++){ // 각 노드마다 DFS 실행
        DFS(i, 1);
        if (arrive_5) {
            break;
        }
    }

    if(arrive_5) {
        cout << 1 << "\n";
    }
    else {
        cout << 0 << "\n";
    }
}

void DFS(int node, int depth) {
    if(depth == 5 || arrive_5){ // DFS 깊이가 5가 되면 종료
        arrive_5 = true;
        return;
    }
    visited[node] = true;

    for(int i : A[node]){
        if(!visited[i]){
            DFS(i, depth+1); // 재귀 방식으로 depth를 1씩 증가하여 호출
        }
    }
    visited[node] = false;
}