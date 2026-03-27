#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, num = 0;

    cin >> N;
    vector<int> card(N);
    for (int i=0; i<N; i++) {
        cin >> card[i];
    }

    sort(card.begin(), card.end());

    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> num;
        if(binary_search(card.begin(), card.end(), num)) {
            cout << '1' << " ";
        }
        else {
            cout << '0' << " ";
        }
    }
}