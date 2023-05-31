import numpy.linalg as linalg
import numpy as np
from fractions import Fraction


def reverse_dfs(m, v, visited):
    if visited[v]:
        return
    visited[v] = True
    for i in range(len(m)):
        if(m[i][v]):
            reverse_dfs(m, i, visited)


def get_matrix_minor(m, i, j):
    return [row[:j] + row[j+1:] for row in (m[:i] + m[i+1:])]


def get_matrix_determinant(m):
    if len(m) == 1:
        return m[0][0]
    if len(m) == 2:
        return m[0][0] * m[1][1] - m[0][1] * m[1][0]

    det = Fraction()
    for c in range(len(m)):
        if m[0][c] == Fraction():
            continue
        det += ((-1)**c) * m[0][c] * \
            get_matrix_determinant(get_matrix_minor(m, 0, c))
    return det


def matrix_mult(mat1, mat2):
    res = [[Fraction()] * len(mat2[0]) for i in range(len(mat1))]
    for i in range(len(mat1)):
        for j in range(len(mat2[0])):
            for k in range(len(mat1[0])):
                res[i][j] += mat1[i][k] * mat2[k][j]
    return res


def get_matrix_inverse(A):
    n = len(A)
    if n == 1:
        return [[Fraction(1, 1)]]
    res = [[Fraction()] * n for i in range(n)]
    det = get_matrix_determinant(A)

    for i in range(n):
        for j in range(n):
            res[j][i] = ((-1)**(i+j)) * \
                get_matrix_determinant(get_matrix_minor(A, i, j)) / det
    return res


class AbsorbingMarkovChain():
    def __init__(self, m):
        if len(m) < 0 or len(m) != len(m[0]):
            raise ValueError('transition matrix has no proper size')

        self.absorbed = self.__get_absorbed_states_bit_mask(m)

        if sum(self.absorbed) == 0:
            raise ValueError(
                'absorbing property violated - no absorbing states')

        if self.__is_closed_cyclic(m):
            raise ValueError(
                'absorbing property violated - closed cycle found')

        if sum(self.absorbed) == len(m):
            raise ValueError('all states are absorbing - trivial case')

        R, Q_stroke = self.__getQR(m)

        self.F = get_matrix_inverse(Q_stroke)
        self.FR = matrix_mult(self.F, R)

    def __get_absorbed_states_bit_mask(self, m):
        res = [bool()]*len(m)

        for i in range(len(m)):
            res[i] = (m[i][i] == sum(m[i]))
        return res

    def __is_closed_cyclic(self, m):
        visited = [False] * len(m)
        for i in range(len(m)):
            if not self.absorbed[i] or visited[i]:
                continue
            reverse_dfs(m, i, visited)
        return sum(visited) != len(m)

    def get_limiting_matrix(self):
        return self.FR

    def get_fundamental_matrix(self):
        return self.F

    def __getQR(self, m):
        x = sum(self.absorbed)
        y = len(m) - x
        Q_stroke = [[Fraction()] * y for i in range(y)]
        R = [[Fraction()] * x for i in range(y)]

        i = 0
        for k in range(len(m)):
            if self.absorbed[k]:
                continue
            j1 = 0
            j2 = 0
            s = sum(m[k])
            for r in range(len(m)):
                if self.absorbed[r]:
                    R[i][j1] = Fraction(m[k][r], 1) / s
                    j1 += 1
                else:
                    if i == j2:
                        Q_stroke[i][j2] = 1 - Fraction(m[k][r], 1) / s
                    else:
                        Q_stroke[i][j2] = -Fraction(m[k][r], 1) / s
                    j2 += 1
            i += 1

        return R, Q_stroke


def solution(m):
    if m[0][0] == sum(m[0]):
        return [1] + [0]*(len(m) - 1) + [1]
    amc = AbsorbingMarkovChain(m)
    lm = amc.get_limiting_matrix()
    divisor = np.lcm.reduce(list(map(lambda x: x.denominator, lm[0])))
    res = list(map(lambda x: divisor // x.denominator * x.numerator, lm[0]))
    res.append(divisor)
    return res


assert (
    solution([
        [0, 1, 0, 0, 0, 1],
        [4, 0, 0, 3, 2, 0],
        [0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]) == [0, 3, 2, 9, 14]
)

assert (
    solution([
        [0, 2, 1, 0, 0],
        [0, 0, 0, 3, 4],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0]
    ]) == [7, 6, 8, 21]
)

assert (
    solution([
        [1, 2, 3, 0, 0, 0],
        [4, 5, 6, 0, 0, 0],
        [7, 8, 9, 1, 0, 0],
        [0, 0, 0, 0, 1, 2],
        [0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]) == [1, 2, 3]
)
assert (
    solution([
        [0]
    ]) == [1, 1]
)

assert (
    solution([
        [0, 0, 12, 0, 15, 0, 0, 0, 1, 8],
        [0, 0, 60, 0, 0, 7, 13, 0, 0, 0],
        [0, 15, 0, 8, 7, 0, 0, 1, 9, 0],
        [23, 0, 0, 0, 0, 1, 0, 0, 0, 0],
        [37, 35, 0, 0, 0, 0, 3, 21, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ]) == [1, 2, 3, 4, 5, 15]
)

assert (
    solution([
        [0, 7, 0, 17, 0, 1, 0, 5, 0, 2],
        [0, 0, 29, 0, 28, 0, 3, 0, 16, 0],
        [0, 3, 0, 0, 0, 1, 0, 0, 0, 0],
        [48, 0, 3, 0, 0, 0, 17, 0, 0, 0],
        [0, 6, 0, 0, 0, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ]) == [4, 5, 5, 4, 2, 20]
)

assert (
    solution([
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ]) == [1, 1, 1, 1, 1, 5]
)

assert (
    solution([
        [1, 1, 1, 0, 1, 0, 1, 0, 1, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 0, 1, 1, 1, 0, 1, 0, 1, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 0, 1, 0, 1, 1, 1, 0, 1, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 0, 1, 0, 1, 0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [1, 0, 1, 0, 1, 0, 1, 0, 1, 1],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ]) == [2, 1, 1, 1, 1, 6]
)

assert (
    solution([
        [0, 86, 61, 189, 0, 18, 12, 33, 66, 39],
        [0, 0, 2, 0, 0, 1, 0, 0, 0, 0],
        [15, 187, 0, 0, 18, 23, 0, 0, 0, 0],
        [1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ]) == [6, 44, 4, 11, 22, 13, 100]
)

assert (
    solution([
        [0, 0, 0, 0, 3, 5, 0, 0, 0, 2],
        [0, 0, 4, 0, 0, 0, 1, 0, 0, 0],
        [0, 0, 0, 4, 4, 0, 0, 0, 1, 1],
        [13, 0, 0, 0, 0, 0, 2, 0, 0, 0],
        [0, 1, 8, 7, 0, 0, 0, 1, 3, 0],
        [1, 7, 0, 0, 0, 0, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ]) == [1, 1, 1, 2, 5]
)
