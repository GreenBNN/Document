# 연속적인 일의 온도 최대 합 / 누적 합 사용
num ,day = map(int, input().split())

a = [int(x) for x in input().split()]

maxTem = -999

for i in range(0,len(a) - day + 1):
    temp = 0
    for tem in range(i,i+day):
        temp += a[tem]
    if temp > maxTem:
        maxTem = temp

print(maxTem)