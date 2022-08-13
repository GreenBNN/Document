# 문자열 사이 * 에 아무거나 넣고 
# 양 끝 같으면 DA 아니면 NE
# 문자열 slicing 
num = int(input())

arr = input()
left, right = arr.split("*")

for i in range(num):
    inputString = input()

    if inputString[:len(left)] == left and inputString[-len(right):] == right and len(arr)-1<=len(inputString):
        print("DA")
    else: 
        print("NE")



