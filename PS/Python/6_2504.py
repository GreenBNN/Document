data = input()
stack = []
i = 0
result = 0
temp = []
idx = -1

while(i < len(data)):
    if data[i:i+2] == '()':
        if len(stack) == 0:
            result += 2
        else :
            temp[idx] += 2
        i += 2
    elif data[i:i+2] == '[]':
        if len(stack) == 0:
            result += 3
        else :
            temp[idx] += 3
        i += 2
    elif data[i] == '(':
        stack.append(data[i])
        temp.append(0)
        idx+=1
        i += 1
    elif data[i] == '[':
        stack.append(data[i])
        temp.append(0)
        idx+=1
        i += 1
    elif data[i] == ')':
        if len(stack) != 0 and stack.pop() == '(':
            if len(stack) == 0:
                result += temp[idx]*2
                temp[idx] = 0
            else :
                temp[idx-1] += temp[idx]*2
                temp.pop()
                idx -= 1
        else :
            result = 0
            break
        i+=1
    elif data[i] == ']':
        if len(stack) != 0 and stack.pop() == '[':
            if len(stack) == 0:
                result += temp[idx]*3
            else :
                temp[idx-1] += temp[idx]*3
                temp.pop()
                idx -= 1
        else :
            result = 0
            break
        i += 1

print(result)
