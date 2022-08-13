# 수평선 (좌표, 색)
# 모든 점에 대해 같은 색이며 가장 가까운 점까지의 거리를 구하고
# 다 더함

num = int(input())

arr = []
sum = 0

# 입력 받을 때 공백 제거 방법


for i in range(num):
    a, b = map(int, input().split())
    arr.append([b, a]) # 색, 좌표

arr.sort() # 색으로 정렬 후 좌표로 정렬

for i in range(0,num):
    if i == 0:
        if arr[i][0] == arr[i+1][0]: # 다음 있으면
            sum += arr[i+1][1] - arr[i][1]
    elif i == num-1: 
        if arr[i][0] == arr[i-1][0]: # 이전 있으면
            sum += arr[i][1] - arr[i-1][1]
    else:
        if arr[i][0] == arr[i+1][0] and arr[i][0] == arr[i-1][0]: # 양쪽이 있으면
            if (arr[i+1][1] - arr[i][1]) > (arr[i][1] - arr[i-1][1]): # 더 작은 거리 더하기
                sum += arr[i][1] - arr[i-1][1]
            else:
                sum += arr[i+1][1] - arr[i][1]

        elif arr[i][0] == arr[i+1][0]: # 다음 만 있으면
            sum += arr[i+1][1] - arr[i][1]
        elif arr[i][0] == arr[i-1][0]: # 이전만 있으면
            sum += arr[i][1] - arr[i-1][1]
        else:
            sum += 0

print(sum)
