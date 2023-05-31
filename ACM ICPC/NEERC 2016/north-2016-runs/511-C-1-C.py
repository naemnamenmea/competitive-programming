import sys

sys.stdin = open("codecoder.in")
sys.stdout = open("codecoder.out", "w")

n = int(input())
a = []
x = []
for i in range(n):
    cc, tf = map(int, input().split())
    a.append((cc, tf, i))
    x.append((tf, i))
x.sort()
lesser = [0 for i in range(n)]
for i in range(n):
    lesser[x[i][1]] = i
a.sort()
ccmax, tfmax, lesmax = a[0][0], a[0][1], lesser[a[0][2]]
temp = []
for i in range(1, n):
    if a[i][0] > ccmax and a[i][1] > tfmax and lesmax < i:
        temp.append(i - 1)
    ccmax = max(ccmax, a[i][0])
    tfmax = max(tfmax, a[i][1])
    lesmax = max(lesmax, lesser[a[i][2]])
temp.append(n - 1)
last = 0
ans = [0 for i in range(n)]
for h in range(n):
    ans[a[h][2]] = temp[last]
    if h in temp:
        last += 1
print(*ans, sep='\n')
