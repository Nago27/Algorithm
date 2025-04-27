N, K = map(int, input().split())
num = list(map(int, input().split()))

check = True 
cnt = 0

def merge_sort(num, p, r):
    if p < r and cnt <= K:
        q = (p + r) // 2
        merge_sort(num, p, q)
        merge_sort(num, q+1, r)
        merge(num, p, q, r)

def merge(num, p, q, r):
    i = p
    j = q + 1
    t = 1
    tmp = []

    global cnt, check

    while i <= q and j <= r:
        if num[i] <= num[j]:
            tmp.append(num[i])
            i += 1
        else:
            tmp.append(num[j])
            j += 1
    
    while i <= q:
        tmp.append(num[i])
        i += 1
    while j <= r:
        tmp.append(num[j])
        j += 1
    
    i = p
    t = 0
    while i <= r:
        num[i] = tmp[t]
        cnt += 1
        if cnt == K:
            check = False
            for id in num:
                print(id, end=" ")
        i += 1
        t += 1


merge_sort(num, 0, N-1)
if(check):
        print(-1)