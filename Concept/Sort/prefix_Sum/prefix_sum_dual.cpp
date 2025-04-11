// N*N 크기의 표에서 (x1,y1) 부터 (x2,y2) 까지의 합을 구하는 프로그램
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M; // N은 크기, M은 합 계산 횟수
    cin >> N >> M;

    vector <vector<int> > D(N+1, vector<int>(N+1, 0));
    vector <vector<int> > A(N+1, vector<int>(N+1, 0));

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> A[i][j];

            //구간 합 공식
            D[i][j] = D[i][j-1] + D[i-1][j] - D[i-1][j-1] + A[i][j];
        }
    }

    for (int i=0; i < M; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int res = D[x2][y2] - D[x1-1][y2] - D[x2][y1-1] + D[x1-1][y1-1];
        cout << res << '\n';  // endl 대신 '\n' 사용 -> 시간초과 현상
    }

    
    return 0;
}