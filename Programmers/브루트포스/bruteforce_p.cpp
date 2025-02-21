// 프로그래머스 완점탐색 알고리즘
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int solution1(vector<vector<int> > sizes) { // 모든 명함을 수납할 수 있는 가장 작은 지갑 (가로, 세로를 회전시켜 바꿀 수 있음)
    int answer = 0;
    int num_max = 0, num_min = 0;

    // sizes[i]씩 탐색하여 큰 수들의 최댓값, 작은 수들 중 최댓값 업데이트
    for(int i = 0; i < sizes.size(); i++){
        int t_max = max(sizes[i][0], sizes[i][1]);
        int t_min = min(sizes[i][0], sizes[i][1]);

        if(num_max < t_max) num_max = t_max;

        if(num_min < num_min) num_min = t_min;
    }

    answer = num_max * num_min;
    
    return answer;
}

// 모의고사
vector<int> solution2(vector<int> answers) {
    vector<int> answer;
    vector<int> correct(3);
    int s1[] = {1,2,3,4,5};
    int s2[] = {2,1,2,3,2,4,2,5};
    int s3[] = {3,3,1,1,2,2,4,4,5,5};
    
    for(int i = 0; i < answers.size(); i++) {  // s1~s3가 반복적으로 탐색하므로 나머지 연산이 있어야함
        if(answers[i] == s1[i%5]) correct[0]++; 
        if(answers[i] == s2[i%8]) correct[1]++;
        if(answers[i] == s3[i%10]) correct[2]++;
    }
    
    int m = *max_element(correct.begin(), correct.end());
    
    for(int i = 0; i < 3; i++) {
        if(m == correct[i]) answer.push_back(i+1);
    }
    return answer;
}

// 입력한 숫자에서 소수 갯수 찾기
bool isprime(int n) {
    if(n <= 1) return false;
    
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    
    return true;
}

int solution3(string numbers) {
    unordered_set<int> answer; // 원소 중복 제거 set
    vector<int> nums(7);
    
    sort(numbers.begin(), numbers.end());
    
    do{
        for(int i = 1; i <= numbers.size(); i++){
            int n = stoi(numbers.substr(0, i));
            
            if(isprime(n)) answer.insert(n);
        }
    }while(next_permutation(numbers.begin(), numbers.end())); // 다른 순열을 만듬
    
    return answer.size();
}

// 프로그래머스 던전 피로도
int solution4(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<int> v;
    
    for(int i = 0; i < dungeons.size(); i++){
        v.push_back(i);
    }
    
    do{
        int temp = k;
        int cnt = 0;
        for(int i = 0; i < v.size(); i++){
            if (temp >= dungeons[v[i]][0]){
                cnt++;
                temp -= dungeons[v[i]][1];
            }
        }
        
        answer = max(answer, cnt);
    }while(next_permutation(v.begin(), v.end())); 
    
    return answer;
}

// 카펫 만들기 (노란색은 갈색 가로-2, 세로-2 형태를 지님)
vector<int> solution5(int brown, int yellow) {
    vector<int> answer;
    int map = brown + yellow;

    for(int h = 3 ;; h++){
        if(map % h == 0){
            int width = map / h;
            if(((h - 2) * (width - 2)) == yellow){
                answer.push_back(width);
                answer.push_back(h);
                break;
            }
        }
    }
    
    return answer;
}

// 모음 사전 (dfs로 구현)
string AEIOU = "AEIOU";
int answer = -1, cnt = 0; // 초기화 시에 둘이 값이 같아서 탐색 진행을 못해서 틀림 ㅋㅋ

void dfs(string s, string word) {
    if (cnt == answer) return;
    
    for(int i = 0; i < 5; i++){
        s += AEIOU[i];
        cnt++;
        
        if(s == word){
            answer = cnt;
            return;
        }
        
        if(s.length() < 5) {
            dfs(s, word);
        }
        s.pop_back();
    }
}

int solution6(string word) {
    dfs("", word);

    return answer;
}

int main() {
    cout << solution1({{60,50}, {30, 70}, {60, 30},{80, 40}}) << "\n";
}