#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* // 백준 11651번
bool comp(pair<int, int>&a, pair<int, int>&b){
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<int, int> > v;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        v.push_back({n1, n2});
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}*/

/*
// 백준 10814번
bool comp(pair<int, string>a, pair<int, string>b) {
    return a.first < b.first;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; 
    cin >> N;

    vector<pair<int, string> > p;

    for (int i = 0; i < N; i++){
        int age;
        string name;

        cin >> age >> name;

        p.push_back({age, name});
    }
    
    // merge 정렬로 수행하며 원소들의 순서를 보장함
    stable_sort(p.begin(), p.end(), comp);

    for (int i = 0; i < N; i++) {
        cout << p[i].first << " " << p[i].second << "\n";
    }
}
*/

// 백준 18870번
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; 
    cin >> N;

    vector<int> pos; // 입력 받을 좌표 리스트
    vector<int> pos_sort; // 정렬된 리스트

    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        pos.push_back(x);
        pos_sort.push_back(x);
    }

    sort(pos_sort.begin(), pos_sort.end());
    // 중복 제거
    pos_sort.erase(unique(pos_sort.begin(), pos_sort.end()), pos_sort.end());

    for (int i = 0; i < N; i++)
    {
        // i번째 요소값의 위치 it
        auto it = lower_bound(pos_sort.begin(), pos_sort.end(), pos[i]);
        cout << it - pos_sort.begin() << ' ';
    }

}