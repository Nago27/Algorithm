// 2차예선 택배 상자 꺼내기 (Lv. 1)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int w, int num) { // n: 총 상자 개수, w: 가로에 놓는 상자 개수, num: 꺼내려는 상자 번호
    int answer = 0;
    vector<vector<int> > storage; // 상자를 넣을 2차원 배열
    int h = n/w + 1; // 상자 높이
    int box = 1; // 채울 상자 번호

    for(int i = 0; i < h; i++){ // 2차원 배열에 상자 채우기 (위에서 부터)
        vector<int> temp;

        for(int j = 0; j < w; j++){
            if (box <= n) { // 현재 상자 번호가 n 범위의 속한 경우
                temp.push_back(box);
                box++;
            }
            else { // 그 이상인 경우
                temp.push_back(0);
            }
        }

        if(i % 2 == 0){ // 위에서 채운다고 가정했을때, 짝수열은 정방향, 홀수열은 역방향
            storage.push_back(temp);
        }
        else {
            reverse(temp.begin(), temp.end());
            storage.push_back(temp);
        }
    }   

    for(int i = 0; i < storage.size(); i++){ // 창고 세로 길이
        for(int j = 0; j < storage[i].size(); j++){ // 창고 가로 길이
            if(num == storage[i][j]){
                int now_h = i;

                while (now_h < h && storage[now_h][j] != 0) {
                    answer++;
                    now_h++;
                }
            }
        }
    }

    /*for(int i = 0; i < storage.size(); i++){ // 창고 세로 길이
        for(int j = 0; j < storage[i].size(); j++){ // 창고 가로 길이
            cout << storage[i][j] << " ";
        }
        cout << "\n";
    }*/

    return answer;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cout << solution(22, 6, 8) << "\n";
    cout << solution(13, 3, 6) << "\n";
}