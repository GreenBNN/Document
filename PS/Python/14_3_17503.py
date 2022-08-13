# N 개의 기간동안 하루에 하나씩 맥주 먹음
# 맥주의 종류는 K 고 각각 선호도, 도수레벨이 있음
# 총 M 의 선호도 합을 만족해야하고 맥주 N 개를 먹는데 필요한 최소 도수 레벨 출력

import sys
input = sys.stdin.readline

import heapq # min 힙이니까 max 만드려면 - 붙여서 넣으면 됨

N, M, K = map(int, input().split())
beers  = []

for i in range(K):
    b = list(map(int, input().split()))
    beers.append(b)
    
beers.sort(key=lambda x:(x[1], x[0]))

like=0
heap = []
result = 0
# 작은 LV 선호도 높은 놈부터 먹기
for beer in beers:
    like += beer[0] 

    heapq.heappush(heap, beer[0])
    if len(heap) == N:
        if like >= M:
            result = beer[1]
            break
        else:
            like -= heapq.heappop(heap) # 선호도 작은 놈이 나가짐
else:
    print(-1)
    exit()
print(result)



