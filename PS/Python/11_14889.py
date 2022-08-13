# 사람 수 N 명(짝수), S 능력치 i/j ////////////////////
# 조합으로 nCn/2 해주고
# 능력치 계산해주기 + min 갱신

from itertools import combinations

N = int(input())
S = [list(map(int, input().split())) for i in range(N)]
number = [i for i in range(N)]

min = int(1e9)

for c in combinations(range(N), N//2):
    visited = [0] * N
    arr1 = []
    arr2 = []
    for i in c:
        visited[i] = 1
        arr1.append(i)

    for i in range(N):
        if visited[i]==0:
            arr2.append(i)

    sum1 = 0
    sum2 = 0
    for i in range(N//2):
        for j in range(N//2):
            if S[arr1[i]][arr1[j]] != 0:
                sum1 += S[arr1[i]][arr1[j]]
            if S[arr2[i]][arr2[j]] != 0:
                sum2 += S[arr2[i]][arr2[j]]

    if abs(sum1-sum2) < min:
        min = abs(sum1-sum2)

print(min)