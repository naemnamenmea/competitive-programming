#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
using namespace std;

long daysInMonth(long m)
{
	switch(m)
	{
		case 1:
			return 31;
			break;
		case 2:
			return 28;
			break;
		case 3:
			return 31;
			break;
		case 4:
			return 30;
			break;
		case 5:
			return 31;
			break;
		case 6:
			return 30;
			break;
		case 7:
			return 31;
			break;
		case 8:
			return 31;
			break;
		case 9:
			return 30;
			break;
		case 10:
			return 31;
			break;
		case 11:
			return 30;
			break;
		case 12:
			return 31;
			break;
	}

	return 0;
}

long integrM(long m)
{
	long sum=0;
	if (m == 1)
		return 0;

	for (long i = 1; i < m; i++)
	{
		sum += daysInMonth(m);
	}

	return sum;
}



struct OurDate
{
	int y;
	int m;
	int d;
};


int main()
{
	
	ifstream in("king.in");
	ofstream out("king.out");
	
	OurDate nowDate;
	OurDate sons[100];
	long sonsD[100];
	long sonsD2[100];
	long nowD;
	long now18;
	long indexHolder=-1;
	int n;
	long minLive = LONG_MAX;
	in >> nowDate.d >> nowDate.m >> nowDate.y;
	in >> n;

	for (int i = 0; i < n; i++)
	{
		in >> sons[i].d >> sons[i].m >> sons[i].y;
		sonsD[i] = (sons[i].y - 1) * 365 + integrM(sons[i].m) + sons[i].d;
	}

	nowD = (nowDate.y - 1) * 365 + integrM(nowDate.m) + nowDate.d;
	now18 = 18 * 365;

	for (int i = 0; i < n; i++)
	{
		sonsD2[i] = nowD - sonsD[i];
		if (sonsD2[i]>=now18)
			if (sonsD2[i] < minLive)
			{
				indexHolder = i;
				minLive = sonsD2[i];
			}

	}

	if (indexHolder == -1)
		out << indexHolder;
	else
		out << (indexHolder+1);

	return 0;
}

