# N * N 배열
# 항상 자기 위보다 큼

import sys
input = sys.stdin.readline

import heapq

N = int(input())

heap = []

for i in range(N):
    nums = list(map(int, input().split()))

    if not heap:
        for num in nums:
            heapq.heappush(heap, num)
    else:
        for num in nums:
            if heap[0] < num: # min_heap임
                heapq.heappush(heap, num)
                heapq.heappop(heap)
print(heap[0])