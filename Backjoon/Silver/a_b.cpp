#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a, b, res = "";
    int sum = 0;

    // 값을 문자열 형태로 입력 받음
    cin >> a >> b;

    // 입력 받은 두 문자열의 길이가 0 일때까지.
    while(a.size() || b.size() || sum){
        if(a.size()){
            sum += a.back() - '0'; // 맨 뒤 숫자를 더함
            a.pop_back();
        }
        if(b.size()){
            sum += b.back() - '0'; // 맨 뒤 숫자를 더함
            b.pop_back();
        }

        res += (sum % 10) + '0'; // 일의 자리 숫자부터 문자열에 삽입
        sum /= 10;
    }

    reverse(res.begin(), res.end());
    cout << res << "\n";
    return 0;
}