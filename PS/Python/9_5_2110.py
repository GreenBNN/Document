# N 개 집 수직선 (좌표) 중복X
# C 개 공유기 설치
# 한집에 하나만, 인접한 공유기 거리 최대
# C 개의 공유기를 N 개에 적당히 설치

import sys
input = sys.stdin.readline

###### greedy 조합 시간초과
#import itertools 

#N,C = map(int,input().split())

#arr = []
#dif = []
#for i in range(N):
#    arr.append(int(input()))
#arr.sort()
#for i in range(N-1):
#    dif[i] = arr[i+1] - arr[i]

#ans = 0
#for per in itertools.combinations(arr, C): # (1, 2, 4)

#    min = 1000000000
#    for i in range(0,C-1):
#        temp = per[i+1] - per[i]
        
#        if temp <= min:
#            min = temp

#    if min != 1 and ans <= min:
#        ans = min

#print(ans)

N,C = map(int,input().split())

arr = []
for i in range(N):
    arr.append(int(input()))
arr.sort()

def judge(mid):
    cnt = 1
    current = arr[0] # 공유기 첫번째집 설치

    for i in range(1,len(arr)):
        if arr[i] >= current + mid: # 거리 기준으로 설치 가능
            current = arr[i] # 다음 집 설치
            cnt += 1
    if cnt >= C:
        return True
    else:
        return False

lo = 2
hi = arr[-1] - arr[0]
ans = 0
while lo <= hi:
    mid = (lo + hi) // 2
    if(judge(mid)):
        lo = mid + 1
    else:
        hi = mid - 1

print(hi)
