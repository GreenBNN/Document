import sys
from collections import deque

N,M = map(int,sys.stdin.readline().split())
# 가지고 있는 덱 생성
do_que  = deque()
su_que = deque()

# 그라운드에 놓는 덱 생성
for _ in range(N):
    do,su = map(int,sys.stdin.readline().split())
    do_que.append(do)
    su_que.append(su)

do_check = 0
su_check = 0

do_tmp = deque()
su_tmp = deque()


for i in range(M):
    if i % 2 == 0:
        do_check = do_que.pop()
        do_tmp.append(do_check)
    else:
        su_check = su_que.pop()
        su_tmp.append(su_check)

    if len(do_que) == 0:
        print("su")
        exit()
    elif len(su_que) == 0:
        print("do")
        exit()

    if (do_check + su_check == 5) and (do_check != 0) and (su_check != 0):
        if do_tmp:
            su_que.extendleft(do_tmp)
            do_check = 0
            do_tmp = deque()
        if su_tmp:
            su_que.extendleft(su_tmp)
            su_check = 0
            su_tmp = deque()

    elif (do_check == 5) or (su_check == 5):
        if su_tmp:
            do_que.extendleft(su_tmp)
            su_check = 0
            su_tmp = deque()
        if do_tmp:
            do_que.extendleft(do_tmp)
            do_check = 0
            do_tmp = deque()

if len(do_que) > len(su_que):
    print("do")
elif len(do_que) < len(su_que):
    print("su")
elif len(do_que) == len(su_que):
    print("dosu")