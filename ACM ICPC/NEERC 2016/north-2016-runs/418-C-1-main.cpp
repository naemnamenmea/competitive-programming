#include <iostream>
#include <fstream>
#include<vector>
using namespace std;



int main()
{
    ifstream fin ("codecoder.in");
    ofstream fout ("codecoder.out");
    vector<int>a,b;
    int n,kol=0;
    fin>>n;
    for (int i=0;i<n;i++)
    {
        int k,l;
        fin>>k>>l;
        a.push_back(k);
        b.push_back(l);
    }

    for (int i=0;i<n;i++)
    {kol=0;
    for (int j=0;j<n;j++)
        if (i!=j)
        {
            if (a[i]>a[j]||b[i]>b[j]) kol++;
        }
     fout<<kol<<endl;
    }
    return 0;
}
