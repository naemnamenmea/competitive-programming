def solution(x, y):
    x = int(x)
    y = int(y)
    res = 0
    while True:
        if x > y:
            x, y = y, x
        if x == 0:
            return 'impossible'
        q = y // x
        y %= x
        if x == 1:
            res += q - 1
            return str(res)
        else:
            res += q
