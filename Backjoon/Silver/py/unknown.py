# 백준 1764번
import sys

N,M = map(int, sys.stdin.readline().split())

not_heard = set()
for _ in range(N):
    not_heard.add(sys.stdin.readline().strip())

not_seen = []
for _ in range(M):
    name = sys.stdin.readline().strip()
    if name in not_heard:
        not_seen.append(name)

not_seen.sort()
print(len(not_seen))

for name in not_seen:
    print(name)