# 다음 팰린드롬 수를 구해라 / 문자열, 숫자 배열 slicing
num = input()
length = len(num)

if (int(num) // 10) < 1:
    if (int(num) == 9):
        result = str(11)
    else:
        result = str(int(num)+1)
else:          
    if int(num[:length//2][::-1]) > int(num[length//2+length%2::]):
        result = num[:length//2+length%2] + num[:length//2][::-1]
    else:
        num = str(int(num[:length//2+length%2])+1)  
        num += num[length//2-1::-1]
        result = num

print(result)


#num = input()
#length = len(num)

#if length == 1:
#        if (num == '9'):
#            newNum = '11'
#        else:
#            newNum = str(int(num)+1)
#else:          
#    if int(num[:length//2][::-1]) > int(num[length//2+length%2::]):
#        newNum = num[:length//2+length%2] + num[:length//2][::-1]
#    else:
#        num = str(int(num[:length//2+length%2])+1) + length//2*'0'
#        length = len(num)
#        newNum = num[:length//2+length%2] + num[:length//2][::-1]

#print(newNum)

if int(num[:length//2]) > int(num[length-1:(length//2 + length % 2) -1:-1]):
        result = num[:length//2+length&2] + num[length//2-1::-1]

if int(num[:length//2][::-1]) > int(num[length//2+length%2::]):
        newNum = num[:length//2+length%2] + num[:length//2][::-1]
