import sys

sys.stdin = open("folding.in")
sys.stdout = open("folding.out", "w")

W, H = map(int, input().split())
w, h = map(int, input().split())

if not (w > h) and (W > H):
    w, h = h, w
if (w > W) or (h > H):
    print(-1)
    exit(0)

ans = 0
while W > w:
    W //= 2
    ans += 1
while H > h:
    H //= 2
    ans += 1
print(ans)
