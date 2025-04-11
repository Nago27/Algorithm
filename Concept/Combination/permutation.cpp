// 백준 1722번, 앞자리 숫자가 i개 결정될때, (N-i)!개의 경우가 나옴
#include <iostream>
using namespace std;

int N;
long fac[21], ans[21]; // 팩토리열 경우의 수 리스트, 정답 출력할 순열 리스트
bool visited[21] = {false}; // 사용한 숫자인지 확인

void mathod1();
void mathod2();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int select;

    cin >> N >> select;
    fac[0] = 1;

    for (int i = 1; i <= N; i++){ // 리스트 초기화
        fac[i] = fac[i-1] * i;
    }

    if(select == 1){
        mathod1();
    }
    else if (select == 2){
        mathod2();
    }
}

void mathod1(){ // K번째 순열 구하기
    long K;
    cin >> K;

    for (int i = 1; i <= N; i++){
        for (int j = 1, cnt = 1; j <= N; j++){ // cnt : 해당 자리에 몇번째 숫자를 사용해야 할지 정하는 변수
            if(visited[j]){
                continue; // 이미 사용한 숫자는 제외
            }
            if (K <= cnt * fac[N-i]){
                K -= ((cnt-1) * fac[N-i]); // 사용한 수로 시작한 순열의 경우의 수를 제외시킴
                ans[i] = j;
                visited[j] = true;
                break;
            }
            cnt++;
        }
    }

    for (int i = 1; i <= N; i++){
        cout << ans[i] << " ";
    }
}

void mathod2(){ // 입력한 순열이 몇번째 순열인지 구하기
    long K = 1;

    for(int i = 1; i <= N; i++){
        cin >> ans[i];
        long cnt = 0;

        for(int j = 1; j < ans[i]; j++){ // 해당 숫자보다 작은 숫자를 카운트
            if(!visited[j]) {
                cnt++;
            }
        }

        K += cnt * fac[N-i]; // 자릿수 개수에 따라 순서 더하기
        visited[ans[i]] = true;
    }
    cout << K << "\n";
}
