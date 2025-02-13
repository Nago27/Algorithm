// 백준 1715번, 우선순위 큐 사용해야함
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, sum = 0;
    cin >> N;

    priority_queue<int, vector<int>, greater<int> > pq; // 우선순위 큐 (오름차순 정렬)
    
    int data;
    for(int i = 0; i < N; i++){
        cin >> data;
        pq.push(data);
    }
    
    while(pq.size() != 1) {
        int data1 = pq.top();
        pq.pop();
        int data2 = pq.top();
        pq.pop();
        sum += data1 + data2;
        pq.push(data1+data2);
    }

    cout << sum << "\n";
}