# 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
# 소수 배열 구하기 (소수 = True, 아니면  = False )


arr = [True for i in range(1000001)]

for i in range(2,1001): # 소수가 아닌 놈 False 로 하기
    if arr[i]:
        for j in range(i + i, 1000001, i):
            arr[j] = False
            
while True:
    n = int(input())

    if n ==0:
        break
    
    for i in range(3,len(arr)):
        if arr[i] and arr[n-i]:
            print(n,"=",i,"+",n-i)
            break
