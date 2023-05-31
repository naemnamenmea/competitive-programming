def parseInt(s, b):
    n = 0
    for d in s:
        n = b * n + int(d)
    return n


def toString(n, b):
    digits = []
    while n > 0:
        digits.append(str(n % b))
        n = n // b
    digits.reverse()
    return ''.join(digits)


def getNextId(x, y, b):
    if b == 10:
        return str(int(x) - int(y))

    dx = parseInt(x, b)
    dy = parseInt(y, b)
    dz = dx - dy
    return toString(dz, b)


def solution(n, b):
    k = len(n)
    count = 0
    m = {}

    while n not in m:
        m[n] = count

        x = ''.join(sorted(n, reverse=True))
        y = ''.join(sorted(n))
        z = getNextId(x, y, b)

        n = '0' * (k - len(z)) + z
        count = count + 1
    return count - m[n]


assert (solution("1211", 10) == 1)
assert (solution("81", 10) == 5)
assert (solution("09", 10) == 5)
assert (solution("9", 10) == 1)
assert (solution("210022", 3) == 3)
