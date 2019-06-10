#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("loto.in");
ofstream fout("loto.out");

#define nmax 1001000

int lp[nmax],v[110],n,i,j,k,s,m,ok,s1,s2;

void reconst(int x)
{
    for(int i=1; i<=n; ++i)
        for(int j=i; j<=n; ++j)
            for(int k=j; k<=n; ++k)
                if(v[i]+v[j]+v[k] == x)
                {
                    fout<<v[i]<<' '<<v[j]<<' '<<v[k]<<' ';
                    return ;
                }
}

int main()
{
    fin>>n>>s;
    for(i=1; i<=n; ++i)
        fin>>v[i];

    m=0;
    for(i=1; i<=n; ++i)
        for(j=i; j<=n; ++j)
            for(k=j; k<=n; ++k)
                lp[++m]=v[i]+v[j]+v[k];

    sort(lp+1,lp+m+1);
    ok=0;

    for(i=1; i<=m; ++i)
    {
        if(binary_search(lp+1,lp+m+1,s-lp[i]))
        {
            s1=lp[i];
            s2=s-lp[i];
            ok=1;
            break;
        }
    }
    if(!ok)
        fout<<"-1";
    else
    {
        reconst(s1);
        reconst(s2);
    }
}
