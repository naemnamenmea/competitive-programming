from unittest import TestCase

from src.find_the_access_codes.find_the_access_codes import solution


class TestFindTheAccessCodes(TestCase):
    def test1(self):
        test_input = [1, 1, 1]
        self.assertEqual(solution(test_input), 1)

    def test2(self):
        test_input = [1, 2, 3, 4, 5, 6]
        self.assertEqual(solution(test_input), 3)

    def test3(self):
        test_input = [1, 5, 6]
        self.assertEqual(solution(test_input), 0)

    def test5(self):
        test_input = range(1, 2001)
        self.assertEqual(solution(test_input), 40888)
