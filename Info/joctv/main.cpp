#include <iostream>
#include <fstream>

using namespace std;

ifstream f("joctv.in");
ofstream g("joctv.out");

int n,v[110][110],mx,i,j,k,s,x;

int main()
{
    f>>n;
    for(i=1; i<=n; ++i)
    for(j=1; j<=n; ++j)
    {
        f>>x;
        v[i][j]=x+v[i-1][j];
    }
    for(i=0; i<n; ++i)
        for(j=i+1; j<=n; ++j)
        {
            s=0;
            for(k=1; k<=n; ++k)
            {
                s+=v[j][k]-v[i][k];
                mx=max(mx,s);
                if(s<0)
                {
                    s=0;
                }
            }
        }
    g   <<mx;
}
