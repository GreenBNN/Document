# K 개의 부등호, K+1 개의 정수
# 부등호를 만족시키고 
# 부등호를 없앤 뒤 정수의 최댓값과 최소값 구하기

K = int(input())
sign = input().split()
visited = [False] * 10
max, min = "", ""

def check(i, j, k): # 부등호를 만족 하는지
    if k == '<':
        return i < j
    if k == '>':
        return i > j
    return True

def solve(cnt, s):
    global max, min
    if cnt == K + 1: # 4. 만약 K + 1 개의 정수가 visited 되었으면 min, max 값 갱신
        if not len(min): 
            min = s
        else:
            max = s
        return

    for i in range(10): # 1. 0 부터 9 까지 모든 경우의 수 생각
        if not visited[i]:
            if cnt == 0 or check(s[-1], str(i), sign[cnt - 1]): # 2. 첫 숫자는 무조건 OK, 이후부터 부등호를 만족하면
                visited[i] = True
                solve(cnt + 1, s + str(i)) # 3. 재귀호출
                visited[i] = False
solve(0, "")
print(max)
print(min)


