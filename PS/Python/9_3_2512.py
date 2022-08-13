# 예산 배정하기
# 모든 요청 가능하면 그대로 배정
# 안된다면 특정한 상한액으로 배정 (상한액 이하는 그대로 배정)

N = int(input())
arr = []

arr = list(map(int,input().split()))
arr.sort()

M = int(input()) # 총 예산


lo = 0
hi = arr[-1]
ans = 0

def judge(mid): # mid 값으로 예산 배정이 가능한가?
    total = 0
    for i in range(N):
        if arr[i] > mid:
            total += mid
        else :
            total += arr[i]
    return total <= M


while lo <= hi:
    mid = (lo+hi) // 2
    if(judge(mid)):
        lo = mid + 1
        ans = mid
    else :
        hi = mid - 1

print(ans)