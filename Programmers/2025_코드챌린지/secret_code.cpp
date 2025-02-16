// 비밀 코드 해독 (Lv.2)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;
vector<vector<int> > combs;

int Combinations(int n, int r){ 
    if(num.size() == 5){
        combs.push_back(num);
        return;
    }

    for(int i=r; i <= n; i++){
        num.push_back(i);
        Combinations(n, i+1);
        num.pop_back();
    }
}

// 1~n까지 / q: 입력한 정수를 담은 배열, ans: 시스템 응답
int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;

    Combinations(n, 1);

    for(auto& c : combs){
        for(int i = 0; i < q.size(); i++){
            int cnt = 0;
            for (int j = 0; j < 5; j++){
                if(find(c.begin(), c.end(), q[i][j]) != c.end()){
                    cnt++;
                }
            }

            if(cnt != ans[i]) return;
        }
        answer++;
    }
    
    return answer;
}