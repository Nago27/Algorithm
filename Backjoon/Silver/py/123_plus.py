# 백준 9095번 1, 2, 3 더하기 (실버 3)
# 규칙-> 점화식: f(n) = f(n-1) + f(n-2) + f(n-3)
def case(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n == 3:
        return 4
    else:
        return case(n-1) + case(n-2) + case(n-3)

T = int(input())
for _ in range(T):
    N = int(input())
    print(case(N))
