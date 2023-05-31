#include <exception>
#include <vector>
#include <string>

#include "test_runner.h"
#include "free-the-bunny-prisoners.h"

void Test1() {
	int n = 3, m = 1;
	Matrix expected{
		{0},
		{0},
		{0}
	};
	Matrix actual = Solution::solution(n, m);
	ASSERT_EQUAL(expected, actual);
}

void Test2() {
	int n = 2, m = 2;
	Matrix expected{
		{0},
		{1},
	};
	Matrix actual = Solution::solution(n, m);
	ASSERT_EQUAL(expected, actual);
}

void Test3() {
	int n = 3, m = 2;
	Matrix expected{
		{0,1},
		{0,2},
		{1,2}
	};
	Matrix actual = Solution::solution(n, m);
	ASSERT_EQUAL(expected, actual);
}

void Test4() {
	int n = 2, m = 1;
	Matrix expected{
		{0},
		{0},
	};
	Matrix actual = Solution::solution(n, m);
	ASSERT_EQUAL(expected, actual);
}

void Test5() {
	int n = 4, m = 4;
	Matrix expected{
		{0},
		{1},
		{2},
		{3}
	};
	Matrix actual = Solution::solution(n, m);
	ASSERT_EQUAL(expected, actual);
}

void Test6() {
	int n = 5, m = 3;
	Matrix expected{
		{0,1,2,3,4,5},
		{0,1,2,6,7,8},
		{0,3,4,6,7,9},
		{1,3,5,6,8,9},
		{2,4,5,7,8,9}
	};
	Matrix actual = Solution::solution(n, m);
	ASSERT_EQUAL(expected, actual);
}

void Test7() {
	int n = 1, m = 0;
	Matrix expected{
		{}
	};
	Matrix actual = Solution::solution(n, m);
	ASSERT_EQUAL(expected, actual);
}

void Test8() {
	int n = 9, m = 0;
	Matrix expected{
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{},
		{}
	};
	Matrix actual = Solution::solution(n, m);
	ASSERT_EQUAL(expected, actual);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, Test1);
	RUN_TEST(tr, Test2);
	RUN_TEST(tr, Test3);
	RUN_TEST(tr, Test4);
	RUN_TEST(tr, Test5);
	RUN_TEST(tr, Test6);
	RUN_TEST(tr, Test7);
	RUN_TEST(tr, Test8);

	return 0;
}