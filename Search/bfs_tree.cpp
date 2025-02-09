// 트리의 지름 구하기 (두 노드 사이의 거리가 가장 긴 것) 
// 임의의 노드에서 가장 긴 경로로 연결된 노드는 트리의 지름에 해당하는 두 노드 중 하나 라는 것을 알아야 함.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> edge; // 목적 노드와 거리 표현
static vector< vector<edge> > tree;
static vector<bool> visited;
static vector<int> dist;  // 거리 저장 배열
void BFS(int node);

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    tree.resize(N+1);

    for (int i = 0; i < N; i++){
        int in;
        cin >> in;
        while (1) {  // n: 목적 노드 , d: 해당 노드간의 거리
            int n, d;
            cin >> n;

            if(n == -1) break;

            cin >> d;
            tree[in].push_back(edge(n, d));
        }
    }

    dist = vector<int> (N+1, 0);
    visited = vector<bool> (N+1, false);
    BFS(1); // 임의의 노드를 노드 1로 정함
    int max = 1;

    for (int i = 2; i <= N; i++) {
        if(dist[max] < dist[i]){
            max = i;
        }
    }
    fill(dist.begin(), dist.end(), 0); // 거리 저장 배열 초기화
    fill(visited.begin(), visited.end(), false); // 방문 배열 초기화
    BFS(max); // 임의의 노드에서 가장 먼 노드를 다시 BFS로 탐색
    sort(dist.begin(), dist.end());
    cout << dist[N] << "\n";
}

void BFS(int node) {
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        myqueue.pop();

        for(edge i : tree[now_node]){
            if(!visited[i.first]){
                visited[i.first] = true;
                myqueue.push(i.first);
            }

            // 거리 배열 업데이트
            dist[i.first] = dist[now_node] + i.second;
        }
    }
}

