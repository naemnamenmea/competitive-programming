import sys

sys.stdin = open("king.in")
sys.stdout = open("king.out", "w")

sons = []
d, m, y = map(int, input().split())
y -= 18
sons = [[y, m, d, 2000]]
n = int(input())
for i in range(1, n + 1):
    sons.append(list(map(int, input().split()))[::-1] + [i])
sons.sort()
i = sons.index([y, m, d, 2000])
if i == 0:
    print(-1)
else:
    print(sons[i - 1][3])
