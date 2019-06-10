#include <iostream>
#include <fstream>
using namespace std;
int t,n,i,j,nr;
char x;
ifstream f("harddp.in");
ofstream g("harddp.out");
int main()
{
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>n;nr=0;
        for(j=0;j<n;j++)
        {
            f>>x;
            nr+=x-'0';
        }
        if(nr<=n/2)
            for(j=0;j<n;j++)
            g<<'1';
        else
            for(j=0;j<n;j++)
            g<<'0';
        g<<'\n';
    }
}
