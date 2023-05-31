import sys

sys.stdin = open("anniversary.in")
sys.stdout = open("anniversary.out", "w")
w, h, x1, y1, x2, y2 = map(int, input().split())
k1 = x1 / y1
k2 = x2 / y2
kmid = (k1 + k2) // 2
# print(k1, k2, kmid)
for yr in range(max(1, kmid - 5000), min(h + 1, kmid + 5000)):
    k0 = w / yr
    # print(w, yr, k0)
    if k1 < k0 < k2 or k2 < k0 < k1:
        print(0, 0, w, yr)
        exit(0)

for xr in range(max(1, kmid - 5000), min(w + 1, kmid + 5000)):
    k0 = xr / h
    # print(xr, h, k0)
    if k1 < k0 < k2 or k2 < k0 < k1:
        print(0, 0, xr, h)
        exit(0)
if abs(k1 - k2) < 1e-6:
    print(w, 0, 0, min(y1, y2) + 1)
