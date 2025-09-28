# 백준 15654번
# N과 M (5)
import sys

N, M = map(int, sys.stdin.readline().split())
num = sorted(list(map(int, sys.stdin.readline().split())))

res = []

def back(depth):
    if depth == M:
        print(' '.join(map(str, res))) # 리스트를 문자열로 바꿔서 출력(, 없애기)
        return
    
    for i in range(N):
        if num[i] not in res:
            res.append(num[i])
            back(depth+1)
            res.pop()

back(0)

