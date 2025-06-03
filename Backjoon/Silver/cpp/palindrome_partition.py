# 백준 2705번 : 팰린드롬 파티션
# dp[0]=1, dp[n] = dp[n] + dp[n-i / 2]
import sys

T = int(input())
num = [int(input()) for _ in range(T)]
maxN = max(num)

# dp[n]: 합이 n인 팰린드롬 파티션의 개수
dp = [0] * (maxN + 1)
# ps[n]: dp의 누적합
ps = [0] * (maxN + 1)

dp[0] = 1
ps[0] = 1

for n in range(1, maxN+1):
    dp[n] = ps[n // 2]
    ps[n] = ps[n-1] + dp[n]

out = (str(dp[N]) for N in num)
sys.stdout.write("\n".join(out))