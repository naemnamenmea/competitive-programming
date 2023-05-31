from itertools import combinations


def solution(num_buns, num_required):
    if num_required == 1:
        num_required = num_buns
    elif num_required == num_buns:
        num_required = 1
    else:
        num_required = num_buns - num_required + 1

    res = [[] for _ in range(num_buns)]
    i = 0
    for cmb in combinations(range(num_buns), num_required):
        for j in cmb:
            res[j].append(i)
        i += 1

    return res
