# N 을 조작해 30 의 배수가 되는 가장 큰 수 만들기
# N 은 최대 10^5 개의 숫자
# 수가 존재 X,  -1 출력
# 마지막 0, 더했을 때 3의 배수

import sys
input = sys.stdin.readline

N = list(input().rstrip())
N.sort(reverse=True)

sum = 0
for i in N:
    sum += int(i)

if N[-1] != "0" or sum%3 != 0:
    print(-1)
else:
    print(''.join(N))


