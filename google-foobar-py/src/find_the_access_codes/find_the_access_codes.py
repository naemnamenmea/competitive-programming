def count_div(l, j):
    res = 0
    for i in range(j):
        if l[j] % l[i] == 0:
            res += 1
    return res


def count_mul(l, j):
    res = 0
    for i in range(j + 1, len(l)):
        if l[i] % l[j] == 0:
            res += 1
    return res


def solution(l):
    res = 0
    for i in range(1, len(l) - 1):
        res += count_div(l, i) * count_mul(l, i)
    return res
