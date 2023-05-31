def get(s):
    b = 0
    g = 0
    s += s[0]
    for i in range(len(s) - 1):
        if s[i - 1] == "B" or s[i + 1] == "B":
            b += 1
        if s[i - 1] == "G" or s[i + 1] == "G":
            g += 1
    return (b, g)

import sys

sys.stdin = open("boysgirls.in")
sys.stdout = open("boysgirls.out", "w")
n, x, y = map(int, input().split())
k = (x + y - n - 4) // 2
b = (n + x - y - 2 * k) // 2
g = (n - x - 2 * k + y) // 2

for b1 in range(max(0, b - 10), min(n, b + 10)):
    for g1 in range(max(0, g - 10), min(n, g + 10)):
        for k1 in range(max(0, k - 10), min(n, g + 10)):
            s = "B" * b1 + "G" * g1 + "BG" * k1
            # print(s)
            if len(s) != n:
                continue
            if (get(s) == (x, y)):
                print(s)
                exit(0)
print("Impossible")
