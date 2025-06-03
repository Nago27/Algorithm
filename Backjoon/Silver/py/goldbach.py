# 백준 17103번 : 골드바흐 파티션
import sys

MAX = 1000000
is_prime = [True] * (MAX + 1)
is_prime[0] = is_prime[1] = False

# 에라토스테네스의 체 (소수 찾는 알고리즘)
for i in range(2, int(MAX ** 0.5) + 1):
    if is_prime[i]:
        for j in range(i*i, MAX+1, i):
            is_prime[j] = False

T = int(sys.stdin.readline())
for _ in range(T):
    n = int(sys.stdin.readline())
    cnt = 0
    for i in range(2, n // 2 + 1):
        if is_prime[i] and is_prime[n-i]:
            cnt += 1
    print(cnt)