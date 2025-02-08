// 등차수열 / 등비수열 다음으로 올 원소 구하기
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, answer;
    cin >> n;

    vector<int> common (n, 0);

    for (int i = 0; i < common.size(); i++){
        cin >> common[i];
    }

    if(common[n-1] - common[n-2] == common[n-2] - common[n-3]) { // 등차수열인 경우
        answer = common[n-1] + common[n-1] - common[n-2];
    }
    else if (common[n-1] / common[n-2] == common[n-2] / common[n-3]){ // 등비수열인 경우
        answer = common[n-1] * (common[n-1] / common[n-2]);
    }

    cout << answer;
}