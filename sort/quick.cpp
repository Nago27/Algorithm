// A를 오름차순 정렬했을 때 앞에서부터 K번째에 있는 수를 출력 (퀵 정렬)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quickSort(vector<int> &A, int start, int end, int K);
int middle_Pivot(vector<int> &A, int start, int end); // 가운데 인덱스를 pivot으로 두고 맨 앞으로 이동

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> A (N,0);

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    quickSort(A, 0, N-1, K-1);
    cout << A[K-1] << "\n";
}

void quickSort(vector<int> &A, int start, int end, int K)
{   
    int pivot = middle_Pivot(A, start, end);
    if (pivot == K){ 
        return;
    }
    else if (K < pivot){ // K가 pivot보다 작으면 왼쪽 그룹만 정렬
        quickSort(A, start, pivot-1, K);
    }
    else { // K가 pivot보다 크면 오른쪽 그룹만 정렬
        quickSort(A, pivot+1, end, K);
    }
}

int middle_Pivot(vector<int> &A, int start, int end)
{   
    if (start + 1 == end){
        if (A[start] == A[end]){
            swap(A[start], A[end]);
        }
        return end;
    }
    
    int m = (start + end) / 2;
    swap(A[start], A[m]); // 중앙값을 1번째 요소로 이동
    int pivot = A[start];
    int i = start+1, j = end;

    while (i <= j){
        while (j >= start+1 && pivot < A[j]){ // 피벗보다 작은 수가 나올 때까지 j--
            j--;
        }
        while (i <= end && pivot > A[i]){ // 피벗보다 큰 수가 나올 때까지 i++
            i++;
        }
        if (i < j){
            swap(A[i++], A[j++]); // 찾은 i와 j를 교환
        }  
        else {
            break;
        }
    }
    // i == j 피벗의 값을 양쪽으로 분리한 가운데에 오도록 설정
    A[start] = A[j];
    A[j] = pivot;
    return j;
}


