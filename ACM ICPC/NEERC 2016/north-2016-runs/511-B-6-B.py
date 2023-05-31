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
b = (2 * x - 4 * k + 4) // 2
g = (y - 2 * k - 2) // 2

for b1 in range(max(0, b - 100), min(n, b + 100)):
    for g1 in range(max(0, g - 100), min(n, g + 100)):
        for k1 in range(max(0, k - 100), min(n // 2, k + 100)):
            s = "B" * b1 + "G" * g1 + "BG" * k1
            # print(s)
            if len(s) != n:
                continue
            if (get(s) == (x, y)):
                print(s)
                exit(0)
print("Impossible")
