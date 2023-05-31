inp = open('anniversary.in')
outp = open('anniversary.out', 'w')
w, h, ax, ay, bx, by = map(int, inp.readline().split())
if ax == bx:
    sx = 0
    sy = ay
    ex = w
    ey = by
else:
    sy = 0
    sx = ax
    ey = h
    ex = bx

print(sx, sy, ex, ey, file=outp)