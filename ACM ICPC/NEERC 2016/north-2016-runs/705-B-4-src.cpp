#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ifstream in("boysgirls.in");
	ofstream out("boysgirls.out");
	int n, x, y;
	in >> n >> x >> y;
	int ones = x+y-n;
	int twos = x - ones;
	int zeros = y - ones;
	if (ones % 2 || ones < 0){
		out << "Impossible";
		return 0;
	}
	string part1;
	string part2;
	if (!(n % 2)){
		
		if (ones == 0){
			if (twos == zeros){
				for (int j = 0; j < n; j++){
					if (j % 2)
						out << "B";
					else
						out << "G";
				}
				return 0;
			}
			else if (twos == n){
				for (int j = 0; j < n; j++){
					out << "B";
				}
			}
			else if (twos == 0){
				for (int j = 0; j < n; j++){
					out << "G";
				}
			}
			else{

				out << "Impossible";
				return 0;
			}
		}
		else if (ones == 2){
			if (zeros >= n / 2){
				for (int i = 0; i < n / 2; i++){
					part1 += "0";
				}
				int nZeros = zeros - n / 2;
				for (int i = 0; i < n / 2; i++){
					if (i == 0){
						part2 += "1";
					}
					else if (nZeros > 0){
						part2 += "0";
						nZeros--;
					}
					else if (nZeros == 0){
						part2 += "1";
						nZeros = -1;
					}
					else { part2 += "2"; 
					}
				}
			}
			if (twos >= n / 2){
				for (int i = 0; i < n / 2; i++)
					part1 += "2";
				int nTwos = twos - n / 2;
				for (int i = 0; i < n / 2; i++){
					if (i == 0){
						part2 += "1";
					}
					else if (nTwos > 0){
						part2 += "2";
						nTwos--;
					}
					else if (nTwos == 0){
						part2 += "1";
						nTwos = -1;
					}
					else part2 += "0";
				}
			}
		}
		else{
			int nTwos = twos;
			int nOnes = ones;
			int nZeros = zeros;
			while (part1.length() < n / 2){
				if (nOnes > 2 && part1.length() < (n / 2 - (n / 2) % 2)){
					part1 += "1";
					nOnes--;
				}
				else if (nTwos){
					part1.insert(1, "2");
					nTwos--;
				}
				else if (nZeros){
					part1 += "0";
					nZeros--;
				}
			}
			while (part2.length() < n / 2){
				if (nOnes){
					part2 += "1";
					nOnes--;
				}
				else if (nTwos){
					part2.insert(1, "2");
					nTwos--;
				}
				else if (nZeros){
					part2 += "0";
					nZeros--;
				}
			}
		}
	}
	else {
		
		int nTwos = twos;
		int nOnes = ones;
		int nZeros = zeros;
		if (nOnes == 0){
			if (nTwos == n && nZeros == 0)
				while (part1.length() < n)part1 += '2';
			else if (nTwos == 0 && nZeros == n)
				while (part1.length() < n)part1 += '0';
			else {
				out << "Impossible";
				return 0;
			}
			
		} else
		while (part1.length() < n){
			if (nOnes){
				part1 += "1";
				nOnes--;
			}
			else if (nTwos){
				part1.insert(1, "2");
				nTwos--;
			}
			else if (nZeros){
				part1 += "0";
				nZeros--;
			}
		}
	}
	string dePart1;
	part1 += part1;
	int i = 0;
	if (part1.find('0') != std::string::npos){
		while (part1[i] != '0') i++;
		char cur = 'G';
		for (int j = i; j < part1.length() / 2 + i; j++){
			dePart1 += cur;
			if(part1[j] == '1')
				if (cur == 'G') cur = 'B'; else cur = 'G';
		}
	}
	else if (part1.find('2') != std::string::npos){
		while (part1[i] != '2') i++;
		char cur = 'B';
		for (int j = i; j < part1.length() / 2 + i; j++){
			dePart1 += cur;
			if (part1[j] == '1')
				if (cur == 'G') cur = 'B'; else cur = 'G';
		}
	}
	else {
		for (int j = 0; j < part1.length()/2; j++){
			if (j % 2)
				dePart1 += "B";
			else
				dePart1 += "G";
		}
	}
	string dePart2;
	if (!part2.empty()){
		
		part2 += part2;
		int i = 0;
		if (part2.find('0') != std::string::npos){
			while (part2[i] != '0') i++;
			char cur = 'G';
			for (int j = i; j < part2.length() / 2 + i; j++){
				dePart2 += cur;
				if (part2[j] == '1')
					if (cur == 'G') cur = 'B'; else cur = 'G';
			}
		}
		else if (part2.find('2') != std::string::npos){
			while (part2[i] != '2') i++;
			char cur = 'B';
			for (int j = i; j < part2.length() / 2 + i; j++){
				dePart2 += cur;
				if (part2[j] == '1')
					if (cur == 'G') cur = 'B'; else cur = 'G';
			}
		}
		else {
			for (int j = 0; j < part2.length() / 2; j++){
				if (j % 2)
					dePart2 += "B";
				else
					dePart2 += "G";
			}
		}
	}
	if (!dePart2.empty()){
		for (int i = 0; i < n; i++){
			if (i % 2) out << dePart1[i / 2];
			else out << dePart2[i / 2];
		}
	}
	else{
		dePart1;
		for (int i = 0; i < dePart1.length(); i += 2)
			out << dePart1[i];
		for (int i = 1; i < dePart1.length(); i += 2)
			out << dePart1[i];
	}
	return 0;
}