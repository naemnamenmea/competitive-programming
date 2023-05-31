from asyncio.windows_events import NULL
from math import sqrt


def gcd(a, b):
    a, b = abs(a), abs(b)
    if b == 0:
        return a
    r = a % b
    while (r > 0):
        a = b
        b = r
        r = a % b
    return b


def fix(a, b):
    if a == 0 and b == 0:
        return 0, 0
    d = gcd(a, b)
    a //= d
    b //= d
    return a, b


def norm(a, b):
    return sqrt((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2)


def next_pos(dimensions, pos, axe, dir, state):


def try_block(your_position, new_pos, distance, visited):
    if norm(your_position, new_pos) > distance:
        return False
    tan_pst = fix(your_position[0] - your_position[0], your_position[1] - your_position[1])
    if tan_pst not in visited:
        visited.add(tan_pst)
    if tan_pfn not in visited:
        visited.add(tan_pst)
    return True


def solution(dimensions, your_position, guard_position, distance):
    visited = set()
    res = 0
    if norm(your_position,guard_position) <= distance:
        res = 1
    v = fix(guard_position[0] - guard_position[0], your_position[1] - your_position[1])
    visited.add(v)
    points = [
        ((your_position, False, False, 0), (guard_position, False, False, 0)),
        ((your_position, False, True, 0), (guard_position, False, True, 0)),
        ((your_position, True, False, 0), (guard_position, True, False, 0)),
        ((your_position, True, True, 0), (guard_position, True, True, 0))
    ]
    layer = 1
    can_extend = True
    while can_extend:
        can_extend = False
        for st, fn in points:
            new_st, axe_st, dir_st, state_st = next_pos(dimensions, *st)
            new_fn, axe_fn, dir_fn, state_fn = next_pos(dimensions, *fn)

            tmp_st = new_st
            tmp_fn = new_fn

            for left in range(-layer, 0):
                tmp_st = next_pos(dimensions, new_st, not axe_st, False, tmp_st)
                tmp_fn = next_pos(dimensions, new_fn, not axe_fn, False, tmp_fn)
                tmp = try_block(tmp_fn)
                if not try_block(tmp_st) and not tmp:
                    break
                if tmp:
                    res += 1
                can_extend = True

            tmp_st = new_st
            tmp_fn = new_fn

            for right in range(0, layer):
                pass
        layer += 1
    return res
