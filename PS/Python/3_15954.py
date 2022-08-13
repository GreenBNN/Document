# 카카오 인형 배열
# 표준편차 = 분산의 제곱근, 분산 = 제곱의 평균 - 평균의 제곱

import sys
import math
from decimal import *

n,k = map(int,sys.stdin.readline().split())

arr = list(map(int,sys.stdin.readline().split()))

result = Decimal('inf')

for i in range(n-k+1):
    sum_val = sum(arr[i:i+k-1]) # 합
    sum_val_sq = sum([v*v for v in arr[i:i+k-1]]) # 제곱의 합
 
    for j in range(k, n-i+1):
        sum_val += arr[i+j-1]
        sum_val_sq += arr[i+j-1] ** 2
        aver = sum_val / Decimal(j)
        std = (sum_val_sq / Decimal(j) - aver ** 2).sqrt()
 
        result = min(result, std)
 
print(result)
