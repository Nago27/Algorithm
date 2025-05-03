// 백준 16457번 (실버1)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, k;
vector<int> quest[101];
vector<bool> visited (101, 0);
int res = 0;

void Solve(int d, int n) { // 깊이 너비 탐색으로 최적의 수 찾기
    if(d == N) {
        int cnt = 0;
        for(int i = 0; i < M; i++){
            bool check = true;
            for(int j = 0; j < k; j++){
                if(!visited[quest[i][j]]){
                    check = false;
                    break;
                }
            }

            if(check) cnt++;
        }

        res = max(res, cnt);
        return;
    }

    for(int i = n; i <= N*2; i++){
        if(!visited[i]) {
            visited[i] = true;
            Solve(d+1, i+1); // 재귀함수로 탐색
            visited[i] = false; 
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> k;

    for(int i = 0; i < M; i++){ // 각 퀘스트에 사용해야할 스킬 입력 받기
        for(int j = 0; j < k; j++){
            int s;
            cin >> s;
            quest[i].push_back(s);
        }
    }

    Solve(0,1);

    cout << res << "\n";
}