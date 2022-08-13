# K 깊이 완전 이진 트리
# LVR 
# 빌딩 번호 순서 > 트리 깊이순으로 출력하기

import sys
input = sys.stdin.readline

K = int(input())

tree = list(map(int, input().split()))

result = [[] for i in range(K)]

def DFS(tree, depth):
    mid = len(tree) // 2

    result[depth].append(tree[mid])

    if len(tree) == 1:
        return

    DFS(tree[:mid], depth+1)
    DFS(tree[mid+1:], depth+1)

DFS(tree, 0)

for i in result:
    print(*i)