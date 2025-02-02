#include <iostream>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int data, num;
    cin >> data >> num;
    int N[100001] = {};

    for (int i = 1; i <= data; i++) {
        int temp;
        cin >> temp;
        N[i] = N[i - 1] + temp;
    }

    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        cout << N[b] - N[a - 1] << '\n';
    }
    
    return 0;
}
