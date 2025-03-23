// 프로그래머스 Lv.1 : 동영상 재생기 / 구현 문제
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int v_len_s, pos_s, op_s, op_e;

bool check_op (int pos){
    if(pos >= op_s && pos < op_e){
        return true;
    }
    else return false;
}

// video_len: 동영상 길이, pos: 수행 직전 재생위치, op_start: 오프닝 시작시간, op_end: 오프닝 종료시간
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    // 전부 초 단위로 변경
    v_len_s = stoi(video_len.substr(0,2)) * 60 + stoi(video_len.substr(3,2));
    pos_s = stoi(pos.substr(0,2)) * 60 + stoi(pos.substr(3,2));
    op_s = stoi(op_start.substr(0,2)) * 60 + stoi(op_start.substr(3,2));
    op_e = stoi(op_end.substr(0,2)) * 60 + stoi(op_end.substr(3,2));

    // 오프닝 건너뛰기
    if(check_op(pos_s)){
        pos_s = op_e;
    }

    for (string c : commands){
        // 10초 전 이동
        if(c == "prev"){
            pos_s = max(0, pos_s - 10);
            if(check_op(pos_s)){
                pos_s = op_e;
            }
        }
        // 10초 후 이동
        else if(c == "next") {
            pos_s = min(v_len_s, pos_s + 10);
            if(check_op(pos_s)){
                pos_s = op_e;
            }
        }
    }

    int t;
    t = pos_s / 60;
    string m = (t < 10 ? "0" : "") + to_string(t);
    t = pos_s % 60;
    string s = (t < 10 ? "0" : "") + to_string(t);

    answer += m + ":" + s;

    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << solution("34:33","13:00","00:55","02:55",["next","prev"]); << "\n"; // 13:00
}