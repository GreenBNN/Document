# 사람 수 N, 보성이 번호 K
# 

N, K = map(int, input().split())

graph = [int(input()) for i in range(N)]

cnt = 0
def dfs(v):
    global cnt
    if cnt > N:
        print(-1)
        return
    
    if v == K:
        print(cnt)
        return
    
    cnt += 1
    dfs(graph[v])

dfs(0)