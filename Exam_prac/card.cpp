// 백준 2164번 , queue 활용
#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    queue<int> card;

    for(int i = 1; i <= N; i++){ // queue에 N장의 카드를 먼저 저장
        card.push(i);
    }

    while(card.size() > 1){
        card.pop();
        card.push(card.front());
        card.pop();
    }
    
    cout << card.front() << "\n";
    return 0;
}