# 한 줄에 하나의 나무 이름 (30글자)
# 최대 10.000 개의 종, 1,000,000그루의 나무
# 중복 된다

# 종은 이름 사전순으로 출력, 그 종의 비율 소수점으로 출력
# key value 로 종과 개수를담고 sort 하기

import sys
input = sys.stdin.readline
trees = {}

N = 0
tree_num = 0

while True:
    tree = input().rstrip()
    if not tree:
        break
    tree_num += 1

    if tree not in trees.keys():
        trees[tree] = 1
    else:
        trees[tree] += 1

sorted_trees = sorted(trees.items(), key=lambda x:x[0])

for tree in sorted_trees:
    per = tree[1] / tree_num *100

    print("%s %.4f" %(tree[0], per))
        