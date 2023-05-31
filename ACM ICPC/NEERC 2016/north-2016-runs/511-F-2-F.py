import sys

sys.stdin = open("folding.in")
sys.stdout = open("folding.out", "w")

W, H = sorted(map(int, input().split()))
w, h = sorted(map(int, input().split()))

if (w > W) or (h > H):
    print(-1)
    exit(0)

ans = 0
while W > w:
    W = W // 2 + W % 2
    ans += 1
while H > h:
    H = H // 2 + H % 2
    ans += 1
print(ans)
