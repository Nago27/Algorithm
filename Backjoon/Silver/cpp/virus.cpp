// 백준 2606 (DFS 문제)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> virus[101];
bool visited[101];
int res = 0;

void dfs(int x) {
    res++;
    visited[x] = true;

    for (int i : virus[x]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, net;
    cin >> N >> net;

    for(int i=0; i < net; i++) {
        int from, to;
        cin >> from >> to;

        virus[from].push_back(to);
        virus[to].push_back(from);
    }
    
    dfs(1);
    cout << res - 1;

    return 0;
}