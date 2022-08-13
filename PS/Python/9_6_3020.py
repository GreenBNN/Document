# 동굴 길이 N, 높이 H
# 석순, 종유석 순서로 (아래 위) 장애물
# 만나는 장애물 수 최소값 구간 수

#count = 0
#for number in data:
#  if count % 2 == 0:
#    count += 1
#    top[number] += 1
#  else:
#    count += 1
#    bottom[h-number+1] += 1

#for i in range(h - 1, 0, -1):
#  top[i] += top[i + 1]

#for i in range(1, h + 1):
#  bottom[i] += bottom[i-1]

#for i in range(1, h + 1):
#  answer[i] = top[i] + bottom[i]

#answer = answer[1:]
#print(min(answer), answer.count(min(answer)))

import sys
input = sys.stdin.readline
from collections import Counter

N, H = map(int, input().split())

top = [0] * (H + 1) # 종유석 
bottom = [0] * (H + 1) # 석순

for i in range(N):
   num = int(input())
   if i % 2 == 0: # 짝수, 아래, 석순
     bottom[num] += 1
   else:
     top[num] += 1

Px, Py = [0]* (H + 1), [0] * (H + 1)
Px[H], Py[1] = top[H], bottom[H]

for r in range(1,H):
    Px[H-r] = Px[H-r+1] + top[H-r]
    Py[r+1] = Py[r] + bottom[H-r]

P = [ 0 for _ in range(H)] 
for r in range(H):
   P[r] = Px[r+1] + Py[r+1]

c = Counter(P)
minXY = list(sorted(c.keys()))[0]
print(minXY, c[minXY])