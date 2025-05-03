# 백준 25966번 : 구현 문제

from sys import stdin

input = stdin.readline

N,M,q = map(int, input().split())
arr = [[0]*M]*N # 배열 초기화

for i in range(N):
    arr[i] = list(map(int, input().split()))

for _ in range(q):
    query = list(map(int, input().split()))

    if(query[0] == 0):
        arr[query[1]][query[2]] = query[3]
    else:
        arr[query[1]], arr[query[2]] = arr[query[2]], arr[query[1]]

for i in range(N):
    res = map(str, arr[i])
    print(" ".join(res))