# 게임 횟수 X
# 이긴 게임 Y
# Z 는 승률 (소수점 버림)
# 게임을 몇번 더 해야 Z 가 변할까?

N, Y  = map(int, input().split())

Z = (Y * 100) // N

#if Z >= 99:
#    print(-1)
#else:
#    result = 0
#    lo = 1
#    while lo <= hi:
#        mid = (lo + hi) // 2
#        if ((Y+mid) * 100) // (N+mid) <= Z: # 확률보다 작으면 이긴 횟수 늘려주기
#            lo = mid + 1
#        else: # 확률보다 크면 줄여주고 mid 저장
#            result = mid
#            hi = mid - 1
#    print(result)



def judge(mid): # mid 로 확률이 바뀌나?
    return ((Y+mid)*100 //(N+mid)) <= Z

if Z >= 99:
    print(-1)
else:
    ans = 0
    lo = 1
    hi = 1000000000
    while lo <= hi:
        mid = (lo + hi) // 2
        if judge(mid): 
            lo = mid + 1
        else: 
            hi = mid - 1
            ans = mid
 
    print(ans)