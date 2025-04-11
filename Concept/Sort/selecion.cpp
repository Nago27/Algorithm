// 수가 주어질때, 그 수의 각 자릿수를 내림차순으로 정리
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string in;
    cin >> in;
    vector <int> A(in.size(),0);

    for(int i = 0; i < in.size(); i++){
        A[i] = stoi(in.substr(i, 1));
    }

    for(int i = 0; i < in.length(); i++){
        int max_index = i;
        for (int j = i+1; j < in.length(); j++){
            if (A[max_index] < A[j]){ // 범위 내 최댓값에 위치를 찾음
                max_index = j;
            }
        }

        if(A[max_index] > A[i]){ // 찾은 최댓값 index를 가장 왼쪽으로 이동
            swap(A[max_index], A[i]);
        }
    }
    
    for (int i=0; i < A.size(); i++){
        cout << A[i];
    }
}