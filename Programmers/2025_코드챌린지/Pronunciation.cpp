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
#include <unordered_map> // 중복 제거 map
#define MAX = 4e5 + 4e2;

using namespace std;

int parent[MAX];
int degree[MAX];

int find(int a){ // 경로 압축: 모든 값의 부모 노드를 root로 만듬
    if(parent[a] == a) {
        return a;
    }

    return parent[a] = find(parent[a]);
}

void union_find(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        parent[b] = a;
    }
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    // nodes: 노드들의 번호를 담긴 배열, edges: 포레스트에 존재하는 간선들의 정보
    // 홀짝트리, 역홀짝트리 개수를 순서대로 담아 return
    // union find 알고리즘 사용
    vector<int> answer;
    int n = nodes.size();
    unordered_map<int, int> node_tree_idx;

    for(int i = 0; i < n; i++){
        parent[i] = i;
        node_tree_idx[nodes[i]] = i;
    }

    for (auto edge : edges){
        int u = node_tree_idx[edge[0]];
        int v = node_tree_idx[edge[1]];

        degree[u]++;
        degree[v]++;
    }

    for (auto edge : edges){
        int u = node_tree_idx[edge[0]];
        int v = node_tree_idx[edge[1]];

        union_find(u, v);
    }


    
    return answer;
}

int main(){


}