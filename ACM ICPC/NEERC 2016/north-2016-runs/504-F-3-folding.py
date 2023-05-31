from math import log2
inp = open('folding.in')
outp = open('folding.out', 'w')
W, H = sorted(list(map(int, inp.readline().split())))
w, h = sorted(list(map(int, inp.readline().split())))
if w > W or h > H:
    ans = -1
else:
    ans = min(-int(-log2(W/w)) -int(log2(H/h)), -int(-log2(H/w)) -int(log2(W/h)))

print(ans, file=outp)