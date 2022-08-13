import sys
from collections import deque

T = int(input())

for i in range(T):
    p = sys.stdin.readline().rstrip()
    n = int(input())
    arr = sys.stdin.readline().rstrip()[1:-1].split(",")
    queue = deque(arr)

    reverse_flag, front, rear = 0,0,len(queue)-1
    continue_flag = 0
    if n == 0 :
        queue = []
        front = 0
        rear = 0

    for j in p:
        if j == 'R':
            reverse_flag += 1
        elif j == 'D':
            if len(queue) <1:
                print("error")
                continue_flag=1
                break
            else:
                if reverse_flag % 2 == 0:
                    queue.popleft()
                else:
                    queue.pop()
    if continue_flag == 0:
        if reverse_flag % 2 == 0:
            print("[" + ",".join(queue) + "]")
        else:
            queue.reverse()
            print("[" + ",".join(queue) + "]")