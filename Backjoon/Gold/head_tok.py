import sys

MAX = 1000000
N = int(sys.stdin.readline())
circle = [int(sys.stdin.readline()) for _ in range(N)]
num = [0] * (MAX+1) # circle의 각 숫자 등장 개수
tok = [0] * (MAX+1) # 톡톡 친 횟수 리스트


for c in circle:
    num[c] += 1

for i in range(1, MAX+1):
    # num[i] != 0일 때
    if num[i]:
        tok[i] += num[i]-1 # 자기 자신 제외
        for j in range(i+i, MAX+1, i):
            tok[j] += num[i]

for i in circle:
    print(tok[i])

