#if !defined(LOCAL_KONTROL) || defined(E_31_03_2017)

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

#ifdef LOCAL_KONTROL
#include <fstream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
#endif

constexpr auto EPS = 1e-7;

using namespace std;

template<class T>
double gcd(T a, T b)
{
  return fabs(b) < 1e-3 ? a : gcd(b, a - floor(a / b) * b);
}

enum class LINE_INTERSECTION_RESULT
{
  LINES_MATCH,
  LINES_ARE_PARALLEL,
  LINES_INTERSECT
};

template<typename T>
inline bool isZero(T val)
{
  return abs(val) < EPS;
}

template<typename T>
inline bool isEqual(T a, T b)
{
  return isZero(a - b);
}

template<typename T>
struct point2d
{
  point2d()
    :x(0), y(0)
  {}

  point2d(T x, T y)
    :x(x), y(y)
  {}

  T operator*(const point2d<T>& p) const
  {
    return this->x * p.x + this->y * p.y;
  }

  inline point2d<T> operator-(const point2d<T>& p) const
  {
    return point2d<T>(this->x - p.x, this->y - p.y);
  }

  inline point2d<T> operator+(const point2d<T>& p) const
  {
    return point2d<T>(this->x + p.x, this->y + p.y);
  }

  inline point2d<T> operator/(const double factor) const
  {
    return point2d<T>(this->x / factor, this->y / factor);
  }

  inline bool operator==(const point2d<T>& p) const
  {
    return this->x == p.x && this->y == p.y;
  }

  inline point2d<T> operator-() const
  {
    return point2d<T>(-this->x, -this->y);
  }

  inline void operator+=(const point2d<T>& p) {
    this->x += p.x;
    this->y += p.y;
  }

  inline double operator~() const
  {
    return sqrt((*this) * (*this));
  }

  T x;
  T y;
};

template<typename T>
double angle_between_two_vectors(const point2d<T>& a, const point2d<T>& b)
{
  return acos((a * b) / (~a) / (~b));
}

template<typename T>
struct line2d
{
  line2d() {}
  line2d(const point2d<T>& dot, const point2d<T>& normal)
    :A(normal.x), B(normal.y), C(-dot * normal)
  {}

  LINE_INTERSECTION_RESULT intersect(const line2d<T>& line, point2d<T>& res) const
  {
    double det = this->A * line.B - line.A * this->B;
    double detX = this->C * line.B - line.C * this->B;
    double detY = this->A * line.C - line.A * this->C;

    if (isZero(det))
    {
      return isZero(detX) && isZero(detY) ?
        LINE_INTERSECTION_RESULT::LINES_MATCH :
        LINE_INTERSECTION_RESULT::LINES_ARE_PARALLEL;
    }

    res = point2d<T>(-detX / det, -detY / det);

    return LINE_INTERSECTION_RESULT::LINES_INTERSECT;
  }

  T A;
  T B;
  T C;
};

template<typename T>
istream& operator >> (istream& is, point2d<T>& p)
{
  return is >> p.x >> p.y;
}

template<typename T>
ostream& operator << (ostream& os, const point2d<T>& p)
{
  return os << p.x << ' ' << p.y;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef LOCAL_KONTROL
  ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif

  constexpr size_t max_n = 100;
  point2d<double> A, B, C, O;
  cin >> A >> B >> C;

  //point2d<double> shift(115, -30);
  //point2d<double> A(0.5, 0), B(-0.5, 0), C(1, sqrt(3) / 2), O;
  //A += shift;
  //B += shift;
  //C += shift;

  point2d<double> midAB((A + B) / 2);
  line2d<double> mid_perpAB(midAB, midAB - A);

  point2d<double> midBC((B + C) / 2);
  line2d<double> mid_perpBC(midBC, midBC - C);

  point2d<double> midAC((A + C) / 2);

  auto junction = mid_perpAB.intersect(mid_perpBC, O);

  if (junction != LINE_INTERSECTION_RESULT::LINES_INTERSECT)
  {
    throw invalid_argument("");
  }

  vector<double> angles{
    angle_between_two_vectors(C - O, B - O),
    angle_between_two_vectors(A - O, B - O),
    angle_between_two_vectors(A - O, C - O)
  };

  sort(begin(angles), end(angles));

  if (isEqual(angles[0] + angles[1], angles[2])) {
    angles[2] = 2 * M_PI - angles[0] - angles[1];
  }

  double R = ~(A - O);

  double alpha = gcd(gcd(angles[0], angles[1]), angles[2]);
  size_t n = 2 * M_PI / alpha;


  cerr << "O = (" << O << ")" << endl;
  cerr << "alpha = " << alpha << endl;
  cerr << "R = " << R << endl;
  cerr << "n = " << n << endl;

  double res = R * R * M_PI * sin(alpha) / alpha;

  cout << fixed << setprecision(8) << res << endl;

  return 0;
}

#endif // E_31_03_2017