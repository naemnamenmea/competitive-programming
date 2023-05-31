from math import log2, inf, ceil
inp = open('folding.in')
outp = open('folding.out', 'w')
W, H = sorted(list(map(int, inp.readline().split())))
w, h = sorted(list(map(int, inp.readline().split())))
if w > W or h > H:
    ans1 = inf
else:
    ans1 = ceil(log2(W/w)) + ceil(log2(H/h))

w, h = h, w
if w > W or h > H:
    ans2 = inf
else:
    ans2 = ceil(log2(W/w)) + ceil(log2(H/h))

ans = min(ans1, ans2)
print(ans if ans < inf else -1, file=outp)