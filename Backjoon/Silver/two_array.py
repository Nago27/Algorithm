# 백준 17124번
T = int(input())

for i in range(T):
    n, m = map(int, input().split())
    A = list(map(int, input().split())) # C[i] 값을 넣는 기준이 되는 배열
    B = list(map(int, input().split())) # C[i]에 값을 저장할 배열
    B.sort()
    C = []
    c_sum = 0

    # 이진 탐색 활용
    for target in A:
        s = 0
        e = m-1
        while s < e:
            mid = (s+e) // 2
            if B[mid] < target:
                s = mid + 1
            else:
                e = mid

        if s == 0:
            tmp = B[s]
        else: # 동일한 조건의 값이 여러개 일 때 절댓값이 작은 값으로 저장
            if s > 0 and abs(B[s-1] - target) <= abs(B[s] - target):
                tmp = B[s-1]
            else:
                tmp = B[s]
        c_sum += tmp
    
    print(c_sum)


