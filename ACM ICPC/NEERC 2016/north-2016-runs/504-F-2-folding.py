from math import log2
inp = open('folding.in')
outp = open('folding.out', 'w')
W, H = sorted(list(map(int, inp.readline().split())))
w, h = sorted(list(map(int, inp.readline().split())))
eps = 1e-15
if w > W or h > H:
    ans = -1
else:
    ans = min(round(log2(W/w) + 0.5 - eps) + round(log2(H/h) + 0.5 - eps), round(log2(H/w) + 0.5 - eps) + round(log2(W/h) + 0.5 - eps))

print(ans, file=outp)