inp = open("folding.in")
outp = open("folding.out", 'w')

str1 = [int(x) for x in inp.readline().split()]
str2 = [int(x) for x in inp.readline().split()]
W0 = str1[0]
H0 = str1[1]
w0 = str2[0]
h0 = str2[1]

W = max(W0, H0)
H = min(W0, H0)
w = max(w0, h0)
h = min(w0, h0)


currH = H
currW = W
res = 0

if h > currH or w > currW:
    outp.write("-1")
    exit(0)

while currH != h or currW != w:
    diff_h = currH - h
    if diff_h > 0: res += 1
    if diff_h < currH / 2:
        currH -= diff_h
    else:
        if currH % 2 == 0:
            currH = currH // 2
        else:
            currH = currH // 2 + 1

    diff_w = currW - w
    if diff_w > 0: res += 1
    if diff_w < currW / 2:
        currW -= diff_w
    else:
        if currW % 2 == 0:
            currW = currW // 2
        else:
            currW = currW // 2 + 1


outp.write(str(res))