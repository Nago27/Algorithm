#백준 1654번 (binary search)
import sys

K, N = map(int, sys.stdin.readline().split())
lan_cables = [int(sys.stdin.readline().strip()) for _ in range(K)]

low = 1
high = max(lan_cables)
res = 0

while low <= high:
    mid = (low + high) // 2

    # mid 길이로 자를 수 있는 랜선의 개수
    count = sum(cable // mid for cable in lan_cables)

    if count >= N: # N개 이상으로 자를 수 있으면, 길이를 늘려본다
        res = mid
        low = mid + 1
    else: # N개 미만으로 자를 수 있으면, 길이를 줄여
        high = mid - 1
        
print(res)

