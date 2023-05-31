def solution(l, t):
    i = j = 0
    acc = 0
    while i <= j and j < len(l):
        if acc + l[j] == t:
            return [i, j]
        if acc < t and acc + l[j] > t:
            if i == j:
                j = i + 1
            else:
                acc = acc - l[i]
            i = i + 1
        elif acc + l[j] > t:
            acc = acc - l[j]
            j = j - 1
        else: # acc + l[j] < t:
            acc = acc + l[j]
            j = j + 1
    return [-1, -1]

assert(solution([4, 3, 5, 7, 8], 12) == [0, 2])
assert(solution([3, 5, 7], 9) == [-1, -1])
assert(solution([1, 3, 5, 7], 8) == [1, 2])
assert(solution([0], 0) == [0, 0])
assert(solution([100], 3) == [-1, -1])
assert(solution([100, 3], 3) == [1, 1])