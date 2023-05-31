from unittest import TestCase

from src.bomb_baby.bomb_baby import solution


class TestBombBaby(TestCase):
    def test_basic(self):
        self.assertEqual(solution('1', '1'), '0')
        self.assertEqual(solution('2', '1'), '1')
        self.assertEqual(solution('4', '7'), '4')
        self.assertEqual(solution('2', '4'), 'impossible')
        self.assertEqual(solution('1', str(int(10e50))), str(int(10e50) - 1))
        self.assertEqual(solution(str(int(10e50)), str(int(10e50) - 1)), str(int(10e50) - 1))
