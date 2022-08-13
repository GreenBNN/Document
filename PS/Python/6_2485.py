# 가로수 일정한 간격으로 추가하기 / 유클리드 호제법

num = int(input())
arr = []
# arr = [0] * num
arrSub = []
result = 0

# from math import gcd
def gcd(a,b):
    if b>a:
        temp = a
        a = b
        b = temp
    while b!=0:
        a, b = b, a%b
    return a

for i in range(num):
    arr.append(int(input()))
    if i != 0:
        arrSub.append(arr[i]- arr[i-1])

arr = list(set(arr))
arr.sort()

GCD = arrSub[0] # 차의 최대공약수 구하기
for i in range(0,len(arrSub)):
    GCD = gcd(GCD,arrSub[i])

for i in arrSub:
    result += i // GCD - 1

print(result)
                