#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int N;
    int answer = 1;
    cin >> N;

    vector< vector<int> > clothes (N,0);

    for (int i = 0; i < N; i++){
        string s;
        cin >> s;
        clothes[i].push_back(s);
    }

    unordered_map<string, int> map;

    for (auto temp : clothes) { // 옷 종류별로 개수 정리
        map[temp[1]]++;
    }

    for (auto m : map){ // 각 옷 종류를 입지 않는 경우가 생기므로 + 1 하고 계산
        answer *= (m.second + 1); 
    }

    cout << answer << "\n";
}