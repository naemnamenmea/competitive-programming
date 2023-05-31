inp = open("anniversary.in")
outp = open("anniversary.out", 'w')

str1 = inp.readline().split()
w = int(str1[0])
h = int(str1[1])
ax = int(str1[2])
ay = int(str1[3])
bx = int(str1[4])
by = int(str1[5])
res = ""

if max(abs(ax - bx), abs(ay - by)) > 1:
    if abs(ax - bx) > abs(ay - by):
        if bx > ax:
            res = str(bx - 1) + " 0 " + str(bx - 1) + " " + str(h)
        else:
            res = str(ax - 1) + " 0 " + str(ax - 1) + " " + str(h)
    elif by > ay:
        res = "0 " + str(by - 1) + " " + str(w) + " " + str(by - 1)
    else:
        res = "0 " + str(ay - 1) + " " + str(w) + " " + str(ay - 1)
else:
    if abs(ax - bx) == 1:
        res = str(bx) + " 0 " + str(ax) + " " + str(h)
    else:
        res = "0 " + str(ay) + " " + str(w) + " " + str(by)
outp.write(res)
inp.close()
outp.close()
