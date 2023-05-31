#include "test_runner.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Solution {
public:
  bool isEmpty(const string& reg)
  {
    if (reg.empty())
      return true;

    if (reg.size() == 1)
      return false;

    for (size_t i = 0; i < reg.size(); i += 2)
    {
      if (reg[i + 1] != '*')
        return false;
    }
    return true;
  }

  bool rec(const string& s, const string& p, size_t si, size_t pi)
  {
    if (si == s.size() && pi == p.size())
    {
      return true;
    }

    if (si == s.size() && pi < p.size())
    {
      return isEmpty(p.substr(pi));
    }

    if (si >= s.size() || pi >= p.size())
    {
      return false;
    }

    const bool ispCurSymbDot = p[pi] == '.';
    const bool ispCurSymbSymb = p[pi] >= 'a' && p[pi] <= 'z';
    const bool isNextSymbPresent = pi + 1 < p.size();

    if (isNextSymbPresent)
    {
      char nextSymb = p[pi + 1];

      if (p[pi] == '*' && nextSymb == '*')
      {
        throw runtime_error("");
      }

      if (nextSymb != '*')
      {
        if (ispCurSymbDot || s[si] == p[pi])
        {
          return rec(s, p, si + 1, pi + 1);
        }
        else
        {
          return false;
        }
      }
      else
      {
        if (ispCurSymbDot && pi + 2 == p.size())
        {
          return true;
        }

        if (rec(s, p, si, pi + 2))
        {
          return true;
        }

        for (size_t i = si; i < s.size(); ++i)
        {
          if (s[i] != p[pi])
          {
            break;
          }

          if (rec(s, p, i + 1, pi + 2))
          {
            return true;
          }
        }
        return false;
      }
    }
    else
    {
      if (ispCurSymbDot || s[si] == p[pi])
      {
        const bool res = si + 1 == s.size() && pi + 1 == p.size();
        return res;
      }
      else
      {
        return false;
      }
    }
  }

  bool isMatch(const string s, const string p) {
    if (s == "")
    {
      return isEmpty(p);
    }
    else
    {
      return rec(s, p, 0, 0);
    }
  }
};

void RunTest(const string& str, const string& pattern, const bool expected)
{
  Solution sol;
  ASSERT_EQUAL(sol.isMatch(str, pattern), expected);
}

void Test1()
{
  RunTest("aa", "a", false);
  RunTest("aa", "a*", true);
  RunTest("ab", ".*", true);
  RunTest("aab", "c*a*b", true);
  RunTest("mississippi", "mis*is*p*.", false);
  RunTest("aba", "a.*c", false);
  RunTest("a", "ab*", true);
  RunTest("bbbba", ".*a*a", true);
}

void RunAllTests()
{
  cout << boolalpha;
  TestRunner tr;

  RUN_TEST(tr, Test1);
}

int main()
{
  RunAllTests();

  return 0;
}
