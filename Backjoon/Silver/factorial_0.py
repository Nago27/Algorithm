def count_zero(n):
    cnt = 0
    while n >= 5:
        cnt += n // 5
        n = n // 5
    
    return cnt

M = int(input())
left = 1
right = M * 5
res = 100000000

while left <= right:
    mid = (left + right) / 2
    tmp = count_zero(mid)

    if tmp < M:
        left = mid + 1
    elif tmp >= M:
        if tmp == M:
            res = mid
        right = mid - 1

if res == 100000000:
    print(-1)
else:
    print(res)