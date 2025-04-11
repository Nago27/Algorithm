// 입력받은 수를 오름차순 정렬 (병합 정렬 이용)
#include <iostream>
#include <vector>
using namespace std;

void merge_sort(int s, int e);
static vector<int> A;
static vector<int> temp;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    A = vector<int> (N+1, 0);
    temp = vector<int> (N+1, 0);

    for (int i=1; i <= N; i++){
        cin >> A[i];
    }

    merge_sort(1,N); // 병합 정렬

    for (int i = 1; i <= N; i++){
        cout << A[i] << "\n"; 
    }
}

void merge_sort(int s, int e)
{
    if (e-s < 1){
        return;
    }

    int mid = s + (e-s) / 2;

    // 재귀함수로 구현
    merge_sort(s, mid);
    merge_sort(mid+1, e);

    for (int i = s; i <= e; i++){
        temp[i] = A[i];
    } 

    int res_index= s;
    int index1 = s; // 앞쪽 그룹 시작점
    int index2 = mid+1; // 뒤쪽 그룹 시작점

    // 양쪽 그룹 index가 가리키는 값을 비교하여 작은 수를 선택해 배열에 저장하고 선택된 데이터의 index값을 한 칸 오른쪽으로 이동
    while (index1 <= mid && index2 <= e){ // 두 그룹 병합
        if (temp[index1] > temp[index2]){ 
            A[res_index] = temp[index2];
            res_index++;
            index2++;
        }
        else {
            A[res_index] = temp[index1];
            res_index++;
            index1++;
        }
    }
    
    while(index1 <= mid){ // 한 쪽 그룹이 모두 선택한 후 남아있는 값 정리
        A[res_index] = temp[index1];
        res_index++;
        index1++;
    }
    
    while (index2 <= e){
        A[res_index] = temp[index2];
        res_index++;
        index2++;
    }
}