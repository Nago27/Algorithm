// 백준 6603번, k개의 수를 골라 집합 S를 만들고 여기서 수를 고르는 경우의 수 출력
#include <iostream>
using namespace std;

static int N;
int S[14];
int lotto[6];

void DFS(int num, int idx){ // num : 집합 S의 인덱스, idx: 출력할 lotto의 인덱스
    if (idx == 6){
        for(int i = 0; i < 6; i++){
            cout << lotto[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = num; i < N; i++){
        lotto[idx] = S[i];
        DFS(i+1, idx+1); 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(1){
        cin >> N;

        if(N == 0) break;

        for(int i = 0; i < N; i++){
            cin >> S[i];
        }

        DFS(0, 0);
        cout << "\n";
    }

}   