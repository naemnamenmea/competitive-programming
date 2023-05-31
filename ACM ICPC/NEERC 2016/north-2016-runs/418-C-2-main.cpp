#include <iostream>
#include <fstream>
#include<vector>

using namespace std;



int main()
{
    ifstream fin ("codecoder.in");
    ofstream fout ("codecoder.out");
    int n=0;
    fin>>n;
    vector<int> a,b;
    for (int i=0;i<n;i++)
    {
        int k=0,l=0;
        fin>>k>>l;
        a.push_back(k);
        b.push_back(l);
    }
    for (int i=0;i<n;i++)
    {
        int k=0;
        for (int j=0;j<n;j++)
        {
            if (i!=j)
                if ((a[i]>=a[j]) || (b[i]>=b[j]))
                k++;
        }
        fout<<k<<endl;
    }
    return 0;
}
