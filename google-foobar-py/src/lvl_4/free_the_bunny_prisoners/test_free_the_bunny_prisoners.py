from unittest import TestCase

from src.free_the_bunny_prisoners.free_the_bunny_prisoners import solution


class TestFreeTheBunnyPrisoners(TestCase):
    def test1(self):
        self.assertEqual([[0], [0], [0]], solution(3, 1))

    def test2(self):
        self.assertEqual([[0, 1], [0, 2], [1, 2]], solution(3, 2))

    def test3(self):
        self.assertEqual([[0], [1], [2]], solution(3, 3))

    def test4(self):
        self.assertEqual([[0]], solution(1, 1))

    def test5(self):
        self.assertEqual([[0], [0]], solution(2, 1))

    def test6(self):
        self.assertEqual([[0], [1]], solution(2, 2))

    def test7(self):
        self.assertEqual([
            [0, 1, 2, 3, 4, 5],
            [0, 1, 2, 6, 7, 8],
            [0, 3, 4, 6, 7, 9],
            [1, 3, 5, 6, 8, 9],
            [2, 4, 5, 7, 8, 9]
        ], solution(5, 3))

    def test11(self):
        self.assertEqual([[0], [0], [0]], solution(3, 1))

    def test12(self):
        self.assertEqual([[0], [1]], solution(2, 2))

    def test13(self):
        self.assertEqual([[0, 1], [0, 2], [1, 2]], solution(3, 2))

    def test14(self):
        self.assertEqual([[0], [0]], solution(2, 1))

    def test15(self):
        self.assertEqual([[0], [1], [2], [3]], solution(4, 4))

    def test16(self):
        self.assertEqual([[]], solution(1, 0))

    def test17(self):
        self.assertEqual([[], [], [], [], [], [], [], [], []], solution(9, 0))

    def test18(self):
        self.assertEqual([[0, 1, 2], [0, 3, 4], [1, 3, 5], [2, 4, 5]], solution(4, 3))
