# 컴퓨터 수 N , 연결 수 L ///////////////
# 1번 컴퓨터를 통해 감염되는(link)된 수 구하기 

N = int(input());
L = int(input());

graph = [[0]*(N+1) for i in range(N+1)] # graph[N][N] / 2차원 리스트 생성
visited = [0]*(N+1)

for i in range(L):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1

def dfs(v):
    visited[v] = 1 # 방문
    for i in range(N+1):
        if graph[v][i] == 1 and visited[i] == 0: # v와 연결, 아직 방문 안함
            dfs(i)

dfs(1) 

cnt = 0
for i in range(N+1):
    if visited[i] == 1:
        cnt+=1

print(cnt-1)
