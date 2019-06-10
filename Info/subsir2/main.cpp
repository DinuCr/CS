#include <iostream>
#include <fstream>

using namespace std;

#define nmax 5100

ifstream fin("subsir2.in");
ofstream fout("subsir2.out");

int v[nmax];
int d[nmax];
int sir[nmax];
int n,i,l,mn,j,ok,p,ans;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    for(i=n; i>0; --i)
    {
        mn=10000;
        p=i;
        ans=10000;
        for(j=i+1; j<=n; ++j)
            if(v[j]>=v[i])
            {
                if(d[j]<ans && v[j]<mn)
                {
                    ans=d[j];
                    p=j;
                }
                else if(d[j]==ans && v[j]<mn)
                {
                    if(v[j]<v[p])
                    {
                        p=j;
                        mn=v[j];
                    }
                }
                mn=min(mn,v[j]);
            }
        if(ans==10000)
            ans=0;
        sir[i]=p;
        d[i]=ans+1;
    }
    mn=100000;
    ans=1000000;
    for(i=1; i<=n; ++i)
    {
        ok=1;
        for(j=1; j<i; ++j)
            if(v[j]<=v[i])
            {
                ok=0;
                break;
            }
        if(ok && d[i]<mn)
        {
            mn=d[i];
            ans=v[i];
            p=i;
        }
        else if(ok && d[i]==mn && v[i]<ans)
        {
            p=i;
            ans=v[i];
        }
    }
    fout<<mn<<'\n';
    while(sir[p]!=p)
    {
        fout<<p<<' ';
        p=sir[p];
    }
    fout<<p;
}
