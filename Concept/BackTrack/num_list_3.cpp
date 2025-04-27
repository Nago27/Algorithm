// 백준 15651번, 모든 수열 출력 (여러번 출력은 X)
#include <iostream>
#include <vector>
using namespace std;

static int N, M; // 자연수 N개, 순열 길이 M
int arr[9];  // 정렬된 순열을 담은 리스트

void DFS(int d){ 
    if(d == M){
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++){
        arr[d] = i;
        DFS(d+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    DFS(0);
}