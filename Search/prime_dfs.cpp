// N자리 숫자 중 각 자릿수가 모두 소수인 수를 오름차순으로 정렬해 출력
#include <iostream>
#include <vector>
using namespace std;

void DFS(int num, int digit);
bool isPrime(int num);
static int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    // 첫 수는 무조건 2,3,5,7로 시작
    DFS(2, 1); 
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
}

void DFS(int num, int digit)
{
    if(digit == N) {
        if(isPrime(num)) {
            cout << num << "\n";
        }
        return;
    }

    for (int i=1; i <= 9; i++){
        if(i % 2 == 0){ // 짝수이면 탐색 필요 없음
            continue;
        }
        if(isPrime(num * 10 + i)) { // 소수일 경우 재귀로 자릿수 + 1
            DFS(num * 10 + i, digit+1);
        }
    }
}

bool isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++){ // 2~num의 제곱근까지로도 소수 판별 가능 
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
