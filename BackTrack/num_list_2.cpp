// 백준 15650번, 이번엔 중복된 숫자가 없이 수열을 출력해야 함
#include <iostream>
using namespace std;

static int N, M; // 자연수 N개, 순열 길이 M
int arr[9];  // 정렬된 순열을 담은 리스트
bool visited[9] = { false };

void DFS(int d, int idx){ // idx : 재귀 호출시 index+1 값을 넘김
    if(d == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = idx; i <= N; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[d] = i;
            DFS(d+1, i+1); 
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    DFS(0,1);
}