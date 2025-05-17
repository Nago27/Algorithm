# 백준 20548번

c = int(input())

digit = 1
res = 0
while(c):
    res = res + (c % 7) * digit
    c = int(c / 7)
    digit = digit * 3

print(res)