import sys

sys.stdin = open("anniversary.in")
sys.stdout = open("anniversary.out", "w")

w, h, ax, ay, bx, by = map(int, input().split())
if ax == bx:
    print(0, by, w, ay)
else:
    print(ax, 0, bx, h)
