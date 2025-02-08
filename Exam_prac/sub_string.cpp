// 문자열 s가 t의 부분 문자열인인지 판단
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t; // s: 부분 문자열 / t: 부분 문자열을 비교할 문자열
    while(cin >> s >> t){
        int res = 0;
        bool check = false;

        for (int i = 0; i < t.length(); i++){ // 각 문자 비교
            if (s[res] == t[i]){
                res++;
            }
            
            if(res == s.length()){
                check = true;
                break;
            }
        }

        if(check) {
            cout << "Yes" << "\n";
        }
        else {
            cout << "No" << "\n";
        }
    }
    return 0;
}