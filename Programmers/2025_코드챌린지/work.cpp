// 유연근무제 (Lv.1)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int min_time (int n){ // 시간 분 단위 변환
    int h = n / 100;
    int m = n % 100;
    return h * 60 + m;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    bool check[1001] = {false}; // 지각한 직원인지 판별

    for(int i = 0; i < schedules.size(); i++){
        int now = startday;
        int work = min_time(schedules[i]);
        check[i] = true;

        for(int t : timelogs[i]){
            if(now == 6 || now == 7) { // 주말 제외
                now++;
                if (now == 8) now = 1; // 일요일이 지나면 월요일(1)로 초기화
                continue;
            }
            else { // 평일
                t = min_time(t);
                if(t > work + 10){ // +10 지각할 경우
                    check[i] = false;
                    break;
                }
                now++;
            }
        }
        if (check[i]) answer++;
    }
    return answer;
}

int main(){
    vector<int> s(1001);
    vector<vector<int> > t(1001, 1001);
    int start;

    solution(s, t, start);
    return 0;
}