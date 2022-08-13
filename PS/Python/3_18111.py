# 마인크래프트 블록 높이 맞추기

import sys

input = sys.stdin.readline

N, M, B = map(int, input().split())
arr = []
HEIS = [0 for _ in range(257)] # 0 으로 초기화
for n in range(N):
    T = list(map(int, input().split()))
    for m in range(M):
        HEIS[T[m]] += 1
    arr.append(T)

m_res, h_res = float('inf'), 0
for h in range(257):
    p = 0
    m = 0
    for b in range(257):
        if h > b:
            p += (h - b) * HEIS[b]
        else:
            m += (b - h) * HEIS[b]
    inven = B + m - p
    if inven < 0:
        continue
    t = m * 2 + p
    if t <= m_res:
        m_res = t
        h_res = h

print(m_res, h_res)