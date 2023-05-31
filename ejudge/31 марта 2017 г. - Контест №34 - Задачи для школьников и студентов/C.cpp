#if !defined(LOCAL_KONTROL) || defined(C_31_03_2017)

#include <iostream>
#include <cmath>

#ifdef LOCAL_KONTROL
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
#endif

constexpr auto EPS = 1e-7;

using namespace std;

template<typename T>
struct point2d {

	point2d()
		:x(0), y(0)
	{}

	point2d(T x, T y)
		:x(x), y(y)
	{}

	T operator*(const point2d<T>& p) const {
		return this->x * p.x + this->y * p.y;
	}

	point2d<T> operator-(const point2d<T>& p) const {
		point2d<T> res;
		res.x = this->x - p.x;
		res.y = this->y - p.y;
		return res;
	}

	bool operator==(const point2d<T>& p) const {
		return this->x == p.x && this->y == p.y;
	}

	T x;
	T y;
};

template<typename T>
istream& operator >> (istream& is, point2d<T>& p) {
	return is >> p.x >> p.y;
}

template<typename T>
ostream& operator << (ostream& os, const point2d<T>& p) {
	return os << p.x << ' ' << p.y;
}

template<typename T>
bool check(const point2d<T>& a, const point2d<T>& b, const point2d<T>& c) {
	if (a==b || a==c || b==c)
		return false;
	return abs((a - c) * (b - c)) < EPS ||
		abs((b - a) * (c - a)) < EPS ||
		abs((a - b) * (c - b)) < EPS;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef LOCAL_KONTROL
	ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

	point2d<double> a, b, c;
	cin >> a >> b >> c;


	if (check(a, b, c))
	{
		cout << "RIGHT";
	}
	else if (
		check(a, b, c - point2d<double>(0, 1)) ||
		check(a, b, c - point2d<double>(1, 0)) ||
		check(a, b, c - point2d<double>(0, -1)) ||
		check(a, b, c - point2d<double>(-1, 0)) ||

		check(a, b - point2d<double>(0, 1), c) ||
		check(a, b - point2d<double>(1, 0), c) ||
		check(a, b - point2d<double>(0, -1), c) ||
		check(a, b - point2d<double>(-1, 0), c) ||

		check(a - point2d<double>(0, 1), b, c) ||
		check(a - point2d<double>(1, 0), b, c) ||
		check(a - point2d<double>(0, -1), b, c) ||
		check(a - point2d<double>(-1, 0), b, c)
		) {
		cout << "ALMOST";
	}
	else {
		cout << "NEITHER";
	}

	return 0;
}

#endif // C_31_03_2017