# 백준 13305번 
N = int(input())

city = list(map(int, input().split()))
oil = list(map(int, input().split()))

min_tax = oil[0]
res = 0

for i in range(N-1):
    if oil[i] < min_tax:
        min_tax = oil[i]
    
    res += min_tax * city[i]

print(res)