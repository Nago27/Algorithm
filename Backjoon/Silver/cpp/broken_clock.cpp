#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    if(a-b > 0){ // 물리적 관점(거속시)로 보았을 때 a/b - 1 수식 검출, 12시간 기준이므로 24시간으로 할려면 *2
        cout << (a-b) * 2 / b << "\n";
    }
    else {
        cout << (a-b) * -2  / b << "\n";
    }
    
}