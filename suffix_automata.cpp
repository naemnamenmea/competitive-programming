#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <unordered_map>

#include "test_runner.h"

using namespace std;

class SuffixAutomata
{
public:
	struct State
	{
		State() : link(-1), len(0) {}
		
		int link;
		size_t len;
		unordered_map<char, int> next;
	};

	SuffixAutomata(size_t max_size = 0)
	{
		Init(max_size);
	}

	SuffixAutomata(const string& str)
	{
		Init(max(0, static_cast<int>(str.size()) * 2 - 1));
		Extend(str);
	}

	void Init(size_t max_size = 0)
	{
		m_states.reserve(max_size);
		m_states.clear();

		m_last = 0;
		m_states.push_back({});
	}

	void Extend(const char c)
	{
		const int cur = static_cast<int>(m_states.size());
		m_states.push_back({});
		m_states[cur].len = m_states[m_last].len + 1;

		int p;
		for (p = static_cast<int>(m_last); p != -1 && !m_states[p].next.contains(c); p = m_states[p].link)
		{
			m_states[p].next[c] = cur;
		}

		if (p == -1)
		{
			m_states[cur].link = 0;
		}
		else
		{
			const int q = m_states[p].next[c];
			if (m_states[p].len + 1 == m_states[q].len)
			{
				m_states[cur].link = q;
			}
			else
			{
				const int clone = static_cast<int>(m_states.size());
				m_states.push_back(m_states[q]);
				m_states[clone].len = m_states[p].len + 1;

				for (; p != -1 && m_states[p].next[c] == q; p = m_states[p].link)
				{
					m_states[p].next[c] = clone;
				}

				m_states[q].link = m_states[cur].link = clone;
			}
		}

		m_last = cur;
	}

	void Extend(const string& str)
	{
		m_states.reserve(max(0, static_cast<int>(str.size()) * 2 - 1));

		for (char c : str)
		{
			Extend(c);
		}
	}

	void Print() const
	{
		for (size_t stateNum = 0; stateNum < m_states.size(); ++stateNum)
		{
			cout << "st. #" << stateNum << ": ("
				<< "link= " << setw(2) << m_states[stateNum].link
				<< "; len= " << setw(2) << m_states[stateNum].len
				<< ")" << endl;

			for (auto [ch, nextStateNum] : m_states[stateNum].next)
			{
				cout << setw(5) << ch << " -> " << nextStateNum << endl;
			}
		}
	}

	bool IsSubstr(const string& t) const
	{
		return process_str(t) != -1;
	}

private:
	vector<State> m_states; // deterministic finite state machine
	size_t m_last;

	int process_str(const string& t) const
	{
		int stateNum = 0;

		for (char ch : t)
		{
			if (!m_states[stateNum].next.contains(ch))
				return -1;

			stateNum = m_states[stateNum].next.at(ch);
		}

		return stateNum;
	}
};

void TestSubstrings()
{
	string text = "abbab";

	SuffixAutomata suffauto(text);

	vector<pair<string, bool>> input = {
		{"abbab", true},
		{"bbab", true},
		{"bab", true},
		{"ab", true},
		{"b", true},
		{"", true},
		{"abab", false},
		{"bba", true},
		{"bbbab", false},
		{"a", true},
		{"bb", true},
		{"abba", true},
		{"aab", false},
		{"aa", false},
	};

	for (const auto& [str, isSubstr] : input)
	{
		ASSERT(suffauto.IsSubstr(str) == isSubstr);
	}
}

void TestReuse()
{
	SuffixAutomata suffauto;

	string text1 = "abbab";
	suffauto.Init();
	suffauto.Extend(text1);

	vector<pair<string, bool>> input1 = {
		{"abbab", true},
		{"bbab", true},
		{"bab", true},
		{"ab", true},
		{"b", true},
		{"", true},
		{"abab", false},
		{"bba", true},
		{"bbbab", false},
		{"a", true},
		{"bb", true},
		{"abba", true},
		{"aab", false},
		{"aa", false},
	};

	for (const auto& [str, isSubstr] : input1)
	{
		ASSERT(suffauto.IsSubstr(str) == isSubstr);
	}

	string text2 = "aabcdda";
	suffauto.Init();
	suffauto.Extend(text2);

	vector<pair<string, bool>> input2 = {
		{"aab", true},
		{"ab", true},
		{"dda", true},
		{"cda", false},
		{"bcd", true},
		{"", true},
		{"aabcdda", true},
		{"aaa", false},
		{"bd", false},
		{"ddb", false},
		{"ca", false},
		{"fabcdda", false},

		{"abbab", false},
		{"bbab", false},
		{"bab", false},
		{"ab", true},
		{"b", true},
		{"abab", false},
		{"bba", false},
		{"bbbab", false},
		{"a", true},
		{"bb", false},
		{"abba", false},
		{"aa", true},
	};

	for (const auto& [str, isSubstr] : input2)
	{
		ASSERT(suffauto.IsSubstr(str) == isSubstr);
	}
}

void TestExtend()
{
	SuffixAutomata suffauto;
	suffauto.Init();
	suffauto.Extend("abbab");
	suffauto.Extend("aabcdda");

	vector<pair<string, bool>> input = {
		{"aab", true},
		{"ab", true},
		{"dda", true},
		{"cda", false},
		{"bcd", true},
		{"", true},
		{"aabcdda", true},
		{"aaa", false},
		{"bd", false},
		{"ddb", false},
		{"ca", false},
		{"fabcdda", false},

		{"abbab", true},
		{"bbab", true},
		{"bab", true},
		{"ab", true},
		{"b", true},
		{"abab", false},
		{"bba", true},
		{"bbbab", false},
		{"a", true},
		{"bb", true},
		{"abba", true},
		{"aa", true},

		{"abaab", true},
		{"baba", true},
		{"baa", true},
	};

	for (const auto& [str, isSubstr] : input)
	{
		ASSERT(suffauto.IsSubstr(str) == isSubstr);
	}
}

void RunTests()
{
	TestRunner tr;
	RUN_TEST(tr, TestSubstrings);
	RUN_TEST(tr, TestReuse);
	RUN_TEST(tr, TestExtend);
}

int main()
{
	RunTests();

	SuffixAutomata sa("ababa");
	sa.Print();

	return 0;
}