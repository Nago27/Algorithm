// 홀짝 트리 (Lv. 3)
/*
    홀수 노드: 노드 번호 홀수, 자식 노드 개수 홀수
    짝수 노드: 노드 번호 짝수, 자식 노드 개수 짝수
    역홀수 노드 : 노드 번호 홀수, 자식 노드 개수 짝수
    역짝수 노드 : 노드 번호 짝수, 자식 노드 개수 홀수

    홀짝 트리: 홀수 노드와 짝수 노드로만 이루어진 트리
    역홀짝 트리: 역홀수 노드와 역짝수 노드로만 이루어진 트리

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > Root;
bool visited[1000001] = {false};
int odd, even, re_odd, re_even;
int odd_even_tree, re_odd_even_tree;

void check_holjak_tree () {
    if((odd == 1 && even = 0) || (odd == 0 && even == 1)){ // 홀짝트리인 경우
        odd_even_tree++;
    }
}

void check_re_holjak_tree () {
    if((re_odd == 1 && re_even = 0) || (re_odd == 0 && re_even == 1)){ // 홀짝트리인 경우
        re_odd_even_tree++;
    }
}

void DFS_Tree (int n) {
    if (n % 2 == 1 && Root[n].size() % 2 == 1) odd++; // 홀수 노드
    if (n % 2 == 0 && Root[n].size() % 2 == 0) even++; // 짝수 노드
    if (n % 2 == 1 && Root[n].size() % 2 == 0) re_odd++; // 역홀수 노드
    if (n % 2 == 0 && Root[n].size() % 2 == 1) re_even++; // 역짝수 노드

    for (auto i : Root[n]){ // DFS로 트리 탐색
        if(visited[i]){
            continue;
        }
        visited[i] = true;
        DFS_Tree(i);
    }
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    // nodes: 노드들의 번호를 담긴 배열, edges: 포레스트에 존재하는 간선들의 정보
    // 홀짝트리, 역홀짝트리 개수를 순서대로 담아 return

    for(auto e : edges) { // 간선 정보 저장
        Root[e[0]].push_back(e[1]);
        Root[e[1]].push_back(e[0]);
    }

    for (auto v : nodes){
        if(visited[v]){
            continue;
        }
        odd = even = re_odd = re_even = 0;
        visited[v] = true;
        DFS_Tree(v);
        check_holjak_tree();
        check_re_holjak_tree();
    }

   
    return {odd_even_tree, re_odd_even_tree};
}

int main(){
    
}