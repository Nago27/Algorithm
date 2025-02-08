// 문자열 s가 t의 부분 문자열인인지 판단
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, t; // s: 부분 문자열 / t: 부분 문자열을 비교할 문자열
    cin >> s >> t;

    vector<string> check;
    for (int i = 0; i < s.length(); i++){ // 부분 문자열을 한문자씩 쪼개기
        check.push_back(s.substr(i,1));
    }

    int res = 0;
    for (int i = 0; i < s.length(); i++){
        for (int j = 0; j < t.length(); j++){
            if(t.substr(j, 1) == check[i]){
                res++;
                break;
            }
        }
    }
    
    if (res == check.size()){ // 부분 문자열의 있는 문자들을 전부 가지고 있을 경우
            cout << "Yes" << "\n";
    }
    else {
        cout << "No" << "\n";
    }
}