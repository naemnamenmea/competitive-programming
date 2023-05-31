#task = 'test'
task = 'folding'


def sol(a, b):
    ans = 0
    while a > b:
        a /= 2
        ans += 1

    return ans


with open(task + '.in', 'r') as fin, open(task + '.out', 'w') as fout:
    a, b = sorted(map(int, fin.readline().split()))
    c, d = sorted(map(int, fin.readline().split()))

    if c > a or d > b:
        print('-1', file=fout)
    else:
        x = sol(a, c) + sol(b, d)
        if d > a or c > b:
            y = sol(a, d) + sol(b, c)
        else:
            y = x
        print(min(x, y), file=fout)