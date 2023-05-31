#task = 'test'
task = 'king'

days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

with open(task + '.in', 'r') as fin, open(task + '.out', 'w') as fout:
    def read_date():
        d, m, y = map(int, fin.readline().split())
        return y * 365 + sum(days[:m-1]) + d

    kd = read_date()
    xs = []
    n = int(fin.readline())

    h = 365 * 18

    for i in range(n):
        xs.append((i, read_date()))

    xs = list(map(lambda x: (x[0], kd - x[1]), xs))
    xs = list(filter(lambda x: x[1] >= h, xs))

    xs.sort(key=lambda p: p[1])

    if len(xs) == 0:
        print('-1', file=fout)
    else:
        print(xs[0][0] + 1, file=fout)