// 특정 초 Second에 트럭이 올라간다면, 그 트럭이 나오는 시간은 Second + bridge_length
// Ex) 1초에 트럭이 한대 올라갔고, 길이가 2인 다리라면 해당 트럭이 나오는 시간은 3초
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int idx = 0;
    int sum = 0; // 현재 다리 위에 올라와 있는 차량 무게 합
    queue<int> q;
    

    while(1) {
        if(idx ==  truck_weights.size()){ // 마지막 트럭
            answer += bridge_length;
            break;
        }

        answer++; // 시간 초 증가
        int tmp = truck_weights[idx];

        if(q.size() == bridge_length) {
            sum -= q.front(); // 다리를 지난 이후 해당 트럭 무게 제외
            q.pop();
        }

        if(sum + tmp <= weight){ // 다음 트럭이 진입 가능하다면
            sum += tmp;
            q.push(tmp);
            idx++; // 다음 트럭
        }
        else {
            q.push(0); // 진입 조건이 안되면 0을 push
        }
    }
    
    return answer;
}

int main() {

}