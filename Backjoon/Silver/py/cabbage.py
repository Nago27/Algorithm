# 백준 1012번 유기농 배추
import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    M, N, K = map(int, input().split())
    graph = [[0] * M for _ in range(N)]
    visited = [[0] * M for _ in range(N)]
    for _ in range(K):
        x, y = map(int, input().split())
        graph[y][x] = 1

    dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    # 재귀 dfs
    def dfs(y, x):
        visited[y][x] = 1
        for dx, dy in dirs:
            nx, ny = x + dx, y + dy
            if 0 <= nx < M and 0 <= ny < N:
                if graph[ny][nx] == 1 and not visited[ny][nx]:
                    dfs(ny, nx) 
    
    count = 0
    for y in range(N):
        for x in range(M):
            if graph[y][x] == 1 and not visited[y][x]:
                dfs(y, x)
                count += 1

    print(count)
