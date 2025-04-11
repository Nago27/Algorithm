// 각 사람이 돈을 인출하는데 걸리는 시간이 주어질 때, 각 사람이 돈 인출하는데 필요한 시간의 합의 최솟값 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N,0); // 정렬된 배열
    vector<int> S(N,0); // 합 배열

    for (int i=0; i < N; i++){
        cin >> A[i];
    }

    for(int i=1; i < N; i++){ // insertion sort
        int ins = i;
        int ins_value = A[i];

        for (int j = i-1; j >= 0; j--){ // 삽입한 위치 부터 i까지 데이터를 한칸씩 밀기
            if (A[j] < A[i]){
                ins = j+1;
                break; 
            }
            if (j == 0){
                ins = 0;
            }
        }

        for(int j = i; j > ins; j--){
            A[j] = A[j-1];
        }
        A[ins] = ins_value;
    }

    S[0] = A[0]; // 합 배열 만들기
    for(int i = 1; i < N; i++){
        S[i] = S[i-1] + A[i];
    }

    int sum = 0;
    for (int i = 0; i < N; i++){ // 내림차순으로 정렬한 합 배열이 가장 최소가 됨
        sum = sum + S[i];
    }

    cout << sum << "\n";
}