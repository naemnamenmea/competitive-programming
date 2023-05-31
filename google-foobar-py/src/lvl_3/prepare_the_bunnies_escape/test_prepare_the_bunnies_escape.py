from unittest import TestCase

from prepare_the_bunnies_escape import solution


class TestPrepareTheBunniesEscape(TestCase):
    def test_1(self):
        res = solution(
            [[0, 1, 1, 0],
             [0, 0, 0, 1],
             [1, 1, 0, 0],
             [1, 1, 1, 0]])
        self.assertEqual(res, 7)

    def test_2(self):
        res = solution(
            [[0, 0, 0, 0, 0, 0],
             [1, 1, 1, 1, 1, 0],
             [0, 0, 0, 0, 0, 0],
             [0, 1, 1, 1, 1, 1],
             [0, 1, 1, 1, 1, 1],
             [0, 0, 0, 0, 0, 0]])
        self.assertEqual(res, 11)
