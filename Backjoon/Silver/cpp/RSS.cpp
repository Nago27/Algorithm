// 백준 14721번
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int data[N][2];
    for (int i=0; i<N; i++) {
        cin >> data[i][0] >> data[i][1];
    }

    long min = LONG_MAX;
    int minA, minB = 0;

    for (int a=1; a<=100; a++) {
        for (int b=1; b<=100; b++) {
            long RSS = 0;
            
            for(int i=0; i<N; i++) {
                long cur = data[i][1] - (data[i][0]*a + b);
                RSS += cur * cur;
            }

            if (min > RSS) {
                min = RSS;
                minA = a;
                minB = b;
            }
        }
    }

    cout << minA << " " << minB;
}