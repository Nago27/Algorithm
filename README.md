# Algorithm

코딩테스트 공부를 위한 repository (C++)

입출력 시간 단축: ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
투 포인터: 2개의 포인터로 알고리즘의 시간 복잡도를 최적화 (배열을 활용)

슬라이딩 윈도우: 2개의 포인터로 범위를 지정한 다음, 범위를 유지한 채로 이동하며 문제 해결
+ 덱(deque): 양 끝에서 데이터를 삽입하거나 삭제할 수 있는 
 -> vector는 삽입과 삭제를 back에서 했을 때 성능이 좋음 / deque는 앞과 뒤에서 삽입과 삭제 성능은 좋으나 그 외에선 좋지 못함

### <정렬 알고리즘>
1. bubble: 두 인접한 데이터의 크기를 비교해 정렬하는 방법 (O(n^2)) + swap연산으로 정렬
2. selecion: 대상 데이터에서 최대나 최소 데이터를 나열한 순으로 찾아가며 선택하는 방법 (O(n^2))
3. insertion: 이미 정렬된 데이터 범위에서 정렬되지 않은 데이터를 적절한 위치에 삽입하여 정렬 (O(n^2))
4. quick: 기준값(pivot)을 선정해 해당 값보다 작은 데이터와 큰 데이터로 분류하는 것을 반복해 정렬 / 평균: O(nlogn), 최악: O(n^2)
-> 기준값 선정에 따라 시간복잡도가 달라짐. 재귀함수 활용 추천
5. merge: 분할 정복 방식을 통해 데이터를 분할하고 분할한 집합을 정렬하며 합침. (O(nlogn))
-> 2개의 그룹 병합시, 투 포인터를 사용하여 병합.

### <탐색>
1. 깊이 우선 탐색(DFS): 그래프의 시작 노드에서 출발하여 탐색할 한쪽 분기를 정해 최대 깊이까지 탐색을 마치고 다른쪽 분기로 이동하여 다시 탐색을 수행 -> 재귀함수를 이용하는데, stack overflow에 유의해야 함. (자료구조 stack 방식)
2. 너비 우선 탐색(BFS): 시작 노드에서 출발해 시작 노드를 기준으로 가까운 노드를 먼저 방문하며 탐색. (자료구조 queue 방식)
  -> 두 노드 사이의 최단경로 or 임의의 경로를 찾고자 할 경우
- 큐에 방문된 노드 삽입 -> 초기 상태 큐는 시작 노드만 저장됨
- 큐에서 노드를 꺼내며 인접 노드를 큐에 삽입. (방문한 노드는 큐에 삽입 X) -> 이를 반복하여 큐에 값이 없을때까지 반복
3. 이진 탐색: 데이터가 정렬된 상태에서 원하는 값을 찾아내는 알고리즘, 데이터의 중앙값 비교를 통한 대상 축소 방식 (O(logn))
- 중앙값 > 타겟 : 중앙값 기준으로 왼쪽 데이터셋 선택 / 중앙값 < 타겟: 중앙값 기준으로 오른쪽 데이터셋 선택 -> 중앙값 == 타겟 일때 탐색 종료 

### <그리디>
: 현재 상태에서 보는 선택지 중 최선의 선택지가 전체 선택지 중 최선의 선택지라고 가정하는 알고리즘

### <조합>
: n개의 숫자에서 r을 고르는 경우의 수 / 실제 알고리즘에서 순열보다 조합 활용이 높음
 #### 조합의 점화식
 - 특정 문제를 가정
 - 모든 부분 문제가 해결된 상황이라고 가정하고 지금 문제 생각하기
 - 특정 문제를 해결한 내용을 바탕으로 일반 점화식 도출

### <동적계획법 (DP)>
: 복잡한 문제를 여러 개의 간단한 문제로 분리하여 부분의 문제들을 해결함으로써 최종 문제의 답을 구함
- 큰 문제를 작은 문제로 나눠야함
- 작은 문제들의 결괏값은 항상 같아야 함
- 모든 작은 문제들은 한번 계산해 DP에 저장하고 추후 제사횽시 이 DP테이블 이용 -> 메모이제이션 기법
- 톱-다운 방식(재귀 함수) / 바텀-업 방식(반복문)으로 구현
=> 점화식을 구하는 것이 중요함

