# 백준 5545번
N = int(input()) # 토핑 종류 갯수
A,B = map(int, input().split()) 
dou_c = int(input()) # 도우 열량
topic_c = [] # 토핑들의 열량

for _ in range(N):
    topic_c.append(int(input()))
topic_c.sort(reverse=True)

res = dou_c / A # 토핑을 하나도 선택하지 않았을 경우

for i in range(1, len(topic_c)+1):
    pizza_cal = dou_c + sum(topic_c[:i])
    cost = A + B * len(topic_c[:i])
    if (pizza_cal / cost) > res:
        res = pizza_cal / cost
    else:
        break

print(int(res))