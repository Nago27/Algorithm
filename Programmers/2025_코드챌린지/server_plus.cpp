#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solution(int players[24], int m, int k) { 
    // 0~23시까지 시간대별 이용자의 수: players, 최대 이용자수:m, 서버 한대가 운용 가능한 시간: k
    int answer = 0;
    queue<int> q;

    for(int i = 0; i < 24; i++){ // i : 시간
        while(!q.empty() && q.front() <= i){ // 현재 queue에 담긴 값이 현재시간과 동일한 경우
            q.pop(); 
        }

        int server_p = players[i] / m; // m만큼의 서버 가용 인원

        if(server_p > q.size()){
            int max_s = server_p - q.size(); 
            answer += max_s;

            for(int j = 0; j < max_s; j++){
                q.push(i + k); // 서버가 증설될 경우 queue에 현재시간 + 서버 가용시간 만큼 push
            }
        }
    }

    return answer;
}

int main(){
    int arr[24] = {0, 2, 3, 3, 1, 2, 0, 0, 0, 0, 4, 2, 0, 6, 0, 4, 2, 13, 3, 5, 10, 0, 1, 5};
    cout << solution(arr, 3, 5) << "\n";
}