# 백준 11650번
N = int(input())

dot = []

for i in range(N):
    dot.append(list(map(int, input().split())))

dot.sort()

for x, y in dot:
    print(x, y)
        