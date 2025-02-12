#include <iostream>
#include <vector>
#include <unordered_set> // 중복을 허용하지 않는 리스트
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, answer = 0;
    cin >> N;
    vector<int> nums (N);
    for (int i = 0; i < N; i++){
        cin >> nums[i];
    }

    unordered_set<int> list;
    for(int i = 0; i < nums.size(); i++){
        list.insert(nums[i]);
    }

    if (nums.size() / 2 < list.size()){
        answer = nums.size() / 2;
    }
    else{
        answer = list.size()
    }

    cout << answer;

}