# 백준 1026번 (그리디 알고리즘)
N = int(input())

A = list(map(int, input().split()))
B = list(map(int, input().split()))
S = 0

# A의 최솟값과 B의 최댓값을 골라 곱하고 리스트에 제외
for i in range(N):
    S += min(A) * max(B)
    A.pop(A.index(min(A)))
    B.pop(B.index(max(B)))

print(S)