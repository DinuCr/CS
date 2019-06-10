#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sortare2.in");
ofstream fout("sortare2.out");

int v[100010];
int i,nr,n;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        int x;
        fin>>x;
        if(v[x-1]==0)
            v[x]=++nr;
        else
            v[x]=v[x-1];
    }
    fout<<nr-1;
}
