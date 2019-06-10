#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("maxsecv.in");
ofstream fout("maxsecv.out");

int v[1000100];
int mx1,mx2;
int i,j,n;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    for(i=1; i<=n; ++i)
    {
        if(v[i])
        {
            int c = 1;
            while(v[i+1])
                ++i,++c;
            if(c>mx1)
            {
                mx2=mx1;
                mx1=c;
            }
            else
            if(c>mx2)
            {
                mx2=c;
            }
        }
    }
    fout<<mx1+mx2;
}
