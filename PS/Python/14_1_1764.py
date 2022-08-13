# N명 M명의 사람 이름이 입력됨
# 둘이 겹치는 사람 사전순 출력 
# 리스트, 튜플, 셋, 딕 https://velog.io/@inyong_pang/Python-List-Tuple-Dictionary-and-Set-%EC%9A%94%EC%95%BD

import sys
input = sys.stdin.readline

N, M = map(int, input().split())
A = []
B = []

for i in range(N):
    name = input().strip()
    A.append(name)

for i in range(M):
    name = input().strip()
    B.append(name)

result = list(set(A)&set(B))
print(len(result))
for name in sorted(result):
    print(name)


