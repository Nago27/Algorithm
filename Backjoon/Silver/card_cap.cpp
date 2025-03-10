// 백준 5587번
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; // 카드 수
    cin >> n;

    vector<int> sang (201, 0);
    vector<int> gen (201, 0);

    for(int i = 0; i < n; i++){ // 상근이 카드  
        int in;
        cin >> in;
        sang[in] = in;
    }

    for(int i = 1; i < 2*n+1; i++){ // 나머지 근상이 카드
        if(sang[i] != i){
            gen[i] = i;
        }
    }

    // 상근이와 근상이의 남은 카드 수
    int sang_card = n;
    int gen_card = n;
    int ind = 1;
    bool seq = true; // 상근 : true / 근상: false;
    while(1){ // 상근이가 무조건 이긴다는 상황임
        if(sang_card == 0 || gen_card == 0){
            break;
        }
        
        if(seq){
            if(sang[ind] != 0){
                sang[ind] = 0;
                sang_card--;
                seq = false;
            }
            ind++;
        }
        else {
            if(gen[ind] != 0){
                gen[ind] = 0;
                gen_card--;
                seq = true;
            }
            ind++;
        }

        if(ind == 2*n + 1){
            ind = 1;
            seq = !seq;
        }
    }

    cout << gen_card << "\n" << sang_card;
}

