// 백준 15918번
// n=3, x=1, y=5 -> [3, 0, 0, 0, 3, 0] -> 1개의 램퍼드 수열
// n=7, x=4, y=10 -> [0,0,0,5,0,0,0,0,0,5,0,0,0,0] 
#include <iostream>
#include <vector>
using namespace std;

int n, x, y, ans = 0;
int arr[25];
bool visited[13]; // 해당 숫자를 탐색했는가

void Find(int num) { // 백트래킹 탐색
    if(num == 2*n){
        ans++;
        return;
    }
    if (arr[num] == 0){
        for(int i = 1; i <= n; i++){
            if(visited[i]){
                continue;
            }
            // 램퍼드 수열에서 적합한 두 인덱스의 값이 비어있는 경우
            if(num + i + 1 <= 2*n && arr[num+i+1] == 0){
                arr[num] = arr[num+i+1] = i;
                visited[i] = true;
                Find(num + 1);
                arr[num] = arr[num+i+1] = 0;
                visited[i] = false;
            }
        }
    }
    else {
        Find(num + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y;

    arr[x] = arr[y] = y-x-1;
    visited[y-x-1] = true; // x, y번째에 기입된 숫자는 이미 규칙에 만족되어 있음
    Find(1);

    cout << ans << "\n";
}