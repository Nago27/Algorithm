#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree[100001];

int parent[100001];
bool visited[100001];

void dfs(int node) {
    visited[node] = true;

    for(int next : tree[node]) {
        if(!visited[next]) {
            parent[next] = node; // 현재 노드가 부모로
            dfs(next); // 자식 노드로 이동하여 탐색
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    // N-1개 간선 정보 입력 
    for(int i=0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // 1을 트리의 루트로 
    dfs(1);

    for(int i=2; i<=N; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
} 