# T 번 테스트
# N 나라 개수 (Node), M 비행기 경로 (edge)
# 모든 나라를 방문하는 edge 최단 거리

import sys
input = sys.stdin.readline

from collections import deque


def DFS(v): # while -> cnt
    s = []
    visited[v] = 1
    s.append(v)
    cnt=0
    while s:
        x = s.pop()
        for nv in graph[x]:
            if visited[nv] ==0:
                visited[nv] = 1
                cnt += 1
                s.append(nv)
    return cnt


def BFS(v): # while -> cnt
    q = deque()
    visited[v] = 1
    q.append(v)
    cnt = 0
    while q:
        x = q.popleft()
        for nv in graph[x]:
            if visited[nv] == 0:
                visited[nv] = 1
                cnt = cnt + 1
                q.append(nv)

    return cnt


T = int(input())

for i in range(T):

    N, M = map(int, input().split())
    graph = [[] for _ in range(N+1)]

    for i in range(M):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    visited = [0] * (N + 1)
    result = BFS(1)
    print(result)


#for i in range(T):
#    N, M = map(int, input().split())
    
#    for i in range(M):
#        a, b = map(int, input().split())

#print(N-1);

#def DFS(idx, cnt):
#        visited[idx] = 1
#        if cnt == N-1:
#            return cnt
#        for i in graph[idx]:
#            if visited == 0 :
#                DFS(i,cnt+1)