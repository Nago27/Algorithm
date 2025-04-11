// 백준 1931번 -> 종료시간 순으로 정리하고 현재시간이랑 가장 가까운 시작시간 회의를 선택
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int> > arr;

    for (int i = 0; i < N; i++){
        int st_time, end_time;
        cin >> st_time >> end_time;
        arr.push_back(make_pair(end_time, st_time)); 
    }
    sort(arr.begin(), arr.end()); // 종료시간 순으로 정렬

    int time = arr[0].first;
    int cnt = 1;
    for (int i = 1; i <= N; i++){
        if(arr[i].second >= time){
            cnt++;
            time = arr[i].first;
        }
    }

    cout << cnt << "\n";
}