# 백준 1058번 : 플로이드-워셜 알고리즘 활용
N = int(input())
friend = [list(input()) for _ in range(N)]
checked = [[0]* N for _ in range(N)] 

for k in range(N):
    for i in range(N):
        for j in range(N):
            if i == j: continue # 본인과는 친구가 아님
            if friend[i][j] == 'Y' or (friend[i][k] == 'Y' and friend[k][j] == 'Y'):
                checked[i][j] = 1

ans = 0
for f in checked:
    ans = max(ans, sum(f))
print(ans)