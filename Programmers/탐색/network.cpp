// BFS로 탐색
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    map<int, vector<int> > m;
    vector<bool> visited (n, false);

    for (int i = 0; i < n; i++) {
        for (int j=0; j < n; j++){
            if(computers[i][j] != 1) continue;

            m[i].push_back(j);
        }
    }


    for (int i = 0; i < n; i++){
        if(visited[i]) continue;

        queue<int> q;
        visited[i] = true;
        answer++;
        q.push(i);

        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for(int j = 0; j < m[now].size(); j++){
                if(visited[m[now][j]]) continue;
                
                visited[m[now][j]] = true;
                q.push(m[now][j]);
            }
        }
    }
    return answer;
}