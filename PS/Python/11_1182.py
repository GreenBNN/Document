# 정수 N 개의 수열, 합이 S 인 부분집합의 개수 ///////////////

N, S = map(int, input().split())

arr = list(map(int, input().split()))

def dfs(idx, sum):
    global cnt
    if idx >= N:
        return
    sum += arr[idx]
    if sum == S:
        cnt += 1
    dfs(idx + 1, sum - arr[idx])
    dfs(idx + 1, sum)

cnt = 0
dfs(0,0)
print(cnt)