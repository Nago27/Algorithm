// 백준 15652번, 비내림차순
#include <iostream>
using namespace std;

static int N, M; // 자연수 N개, 순열 길이 M
int arr[9];  // 정렬된 순열을 담은 리스트

void DFS(int d, int idx){ // idx : 재귀 호출시 index 값을 넘김
    if(d == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = idx; i <= N; i++){
        arr[d] = i;
        DFS(d+1, i); 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    DFS(0,1);
}