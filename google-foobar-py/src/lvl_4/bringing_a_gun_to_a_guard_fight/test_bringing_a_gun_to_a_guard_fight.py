from unittest import TestCase

from src.lvl_4.bringing_a_gun_to_a_guard_fight.bringing_a_gun_to_a_guard_fight import solution


class TestBringingGun(TestCase):
    def test1(self):
        test_input = ([3, 2], [1, 1], [2, 1], 4)
        self.assertEqual(7, solution(*test_input))

    def test2(self):
        test_input = ([300, 275], [150, 150], [185, 100], 500)
        self.assertEqual(9, solution(*test_input))
