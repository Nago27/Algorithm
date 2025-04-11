// 백준 1541번, 소괄호 배치로 최솟값 만들기 -> 가능한 한 큰 수를 빼야하므로 더하기를 전부 괄호쳐서 먼저 계산한다
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    string num = ""; // 숫자를 담는 변수
    int res = 0;
    bool is_minus = false; // '-' 판별 변수
    
    for(int i = 0; i <= str.size(); i++){
        if(str[i] == '-' || str[i] == '+' || i == str.size()){
            if(is_minus){
                res -= stoi(num); 
                num = "";
            }
            else {
                res += stoi(num); // - 부호가 나오기 전까진 전부 덧셈
                num = "";
            }
        }
        else{
            num += str[i];
        }

        if(str[i] == '-'){ // '-' 부호가 한번이라도 나오면 그 뒤 숫자들은 전부 빼기 실행
            is_minus = true;
        }
    }   

    cout << res << "\n";
}