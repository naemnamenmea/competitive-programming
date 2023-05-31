/*
## Problem:
  RLE-сжатие

## Constraints:
  Ограничение времени 	1 секунда
  Ограничение памяти 	256Mb
  Ввод 	стандартный ввод или input.txt
  Вывод 	стандартный вывод или output.txt

## Description:
  RLE-сжатие – один из самых простых методов сжатия строки, основанный на сокращении подстрок, 
  состоящих из одинаковых символов. Сжатие осуществляется следующим образом:

  * Строка разбивается на минимальное количество подстрок, состоящих из одинаковых символов. 
  Например, abbcaaa превращается в строки a, bb, c, aaa.
  * Каждая из полученных строк превращается в строку, состоящую из числа и буквы. 
  Числом является количество повторений символа в этой строке, буква берётся из первого символа 
  обрабатываемой строки. Число не добавляется, если количество символов в строке равно единице. 
  Из предыдущего массива строк мы получаем a, 2b, c, 3a.
  * Затем полученные строки конкатенируются в исходном порядке. В рассмотренном примере 
  в итоге получим a2bc3a.

  Вам дана строка s, уже сжатая в RLE-формате. Назовём строку, из которой была получена s, 
  строкой t. Вам даны q запросов, каждый из них представлен целыми числами l и r. 
  В каждом запросе вам необходимо найти длину сжатой подстроки t[l…r].

## Формат ввода:
  В первой строке входного файла записана строка s, состоящая из строчных букв латинского алфавита 
  и цифр (1≤|s|≤1000000). Гарантируется, что существует такая непустая строка t, из которой 
  RLE-сжатием получается строка s. Также гарантируется, что в строке t не было больше 
  1000000000 одинаковых подряд идущих символов.
  В следующей строке дано количество запросов q(1≤q≤100000). Каждая из следующих q строк 
  содержит два числа li и ri(1≤li≤ri≤|t|) — параметры запросов.

## Формат вывода:
  Выведите q чисел, каждое в отдельной строке — ответы на запросы в том порядке, 
  в котором запросы были заданы во входных данных.

## Пример 1:
  Ввод:
    a2bc3a
    5
    1 7
    5 7
    1 2
    3 5
    4 4
  Вывод:
    6
    2
    2
    3
    1

## Пример 2:
  Ввод:
    x1000000000yz
    3
    2 1000000001
    2 1000000002
    5938493 15938493
  Вывод:
    11
    12
    9
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct ff
{
	ll len_before;
	ll el_here;
	ll len_here;
};

ll symbolsToRLE(ll x) {
	if (x > 1) {
		ll res = 0;
		while (x > 0) {
			++res;
			x /= 10;
		}
		// Размер вычисляется с учетом символа!!
		return res + 1;
	}

	return x;
}

inline bool isSymbol(char c) {
	return c < '0' || c > '9';
}

void InitializeMap(map<ll, ff>& m, const string& s) {
	bool flag = false;
	string num;
	ll cnt = 0;
	ll len = 0;

	for (char c : s) {
		if (isSymbol(c)) {
			ll len_prev = len;
			ll cnt_prev = cnt;
			if (flag) {
				flag = false;
				cnt += stoi(num);
			}
			else {
				cnt += 1;
			}
			auto re = symbolsToRLE(cnt - cnt_prev);
			len = len_prev + re;
			m[cnt_prev] = { len_prev,cnt - cnt_prev, re };
			num.clear();
		}
		else {
			flag = true;
			num += c;
		}
	}
}



int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
#ifdef LOCAL_KONTROL
	ifstream ifs("input.txt"); cin.rdbuf(ifs.rdbuf());
#endif
	string s;
	cin >> s;
	ll q, l, r;
	map<ll, ff> m;

	InitializeMap(m, s);

	cin >> q;
	while (q--)
	{
		cin >> l >> r;
		auto lit = prev(m.lower_bound(l));
		auto rit = prev(m.upper_bound(r));

		ll res;

		if (lit == rit) {
			res = symbolsToRLE(r - l + 1);
		}
		else {
			res = rit->second.len_before - (lit->second.len_before + lit->second.len_here)
				+ symbolsToRLE(r - rit->first)
				+ symbolsToRLE(lit->first + lit->second.el_here - l + 1);
		}

		cout << res << endl;
	}

	return 0;
}