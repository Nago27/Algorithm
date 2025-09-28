# 백준 1620번: 나는야 포켓몬 마스터 이다솜
import sys

N, M = map(int, sys.stdin.readline().split())

poketmons = {} # 포켓몬 이름과 번호를 매핑하는 딕셔너리

for i in range(1, N + 1):
    name = sys.stdin.readline().strip()
    poketmons[name] = str(i)
    poketmons[str(i)] = name

for _ in range(M):
    ans = sys.stdin.readline().strip()

    print(poketmons[ans])
