# 기타 시리얼 번호 입력
# 받은 알파뱃, 숫자를 순서에 맞게 출력
# 1. 길이가 짧은 것 먼저
# 2. 같다면 숫자의 합이 작은 놈
# 3. 사전순 ( 숫자 < 알파벳 ) 

num = int(input())

arr = []
for i in range(num):
    a = input()
    arr.append(a)

# list > sort > 정렬해주기
arr.sort() #오름차순 정렬 (숫자>문자열)

#sort 안에 정렬이 되는 data = key
#lambda 는 복수개의 정렬 ( x:(a,b) a정렬 후 b정렬 )

#오름차순(첫글자) 길이 숫자의 합 완료
arr.sort(key = lambda x:(len(x), sum(int(a) for a in x if a.isnumeric()))) 

for i in range(num):
    print(arr[i])


