#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int kDay, kMonth, kYear, minDay, minMonth, minYear, Day, Month, Year;
    int N, numOfNewKing = -2, i;
    bool flag;
    fstream fileStream;
    fileStream.open("king.in", ios::in);
    fileStream >> kDay >> kMonth >> kYear >> N;
    minDay = 0;
    minYear = 0;
    minMonth = 0;
    for (i = 0; i < N; ++i)
    {
        fileStream >> Day >> Month >> Year;
        flag = false;
        if (kYear - Year >= 18)
        {
            // Для 17 лет
            if (kYear - Year > 18) flag=true;
            if (kYear - Year == 18 && kMonth - Month >= 0)
            {
                if (kMonth > Month) flag = true;
                if (kMonth == Month && kDay >= Day) flag = true;
            }
        }
        if (flag)
        {
            if (Year >= minYear)
            {
                if (Year > minYear)
                {
                    minYear = Year;
                    minDay = Day;
                    minMonth = Month;
                    numOfNewKing = i;
                }
                if (Year == minYear && minMonth - Month <= 0)
                {
                    if (minMonth < Month)
                    {
                        minYear = Year;
                        minDay = Day;
                        minMonth = Month;
                        numOfNewKing = i;
                    }
                    if (minMonth == Month && minDay <= Day)
                    {
                        minYear = Year;
                        minDay = Day;
                        minMonth = Month;
                        numOfNewKing = i;
                    }
                }
            }
        }
    }
    fileStream.close();
    fileStream.open("king.out", ios::out);
    fileStream << numOfNewKing + 1;
    fileStream.close();
    return 0;
}
