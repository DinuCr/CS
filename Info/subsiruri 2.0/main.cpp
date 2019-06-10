#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("subsiruri.in");
ofstream fout("subsiruri.out");

#define mod 9901
#define nmax 1100

int v[nmax];
int d[nmax];
int nr[nmax];
int ans,mx,i,j,n,p;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
        p=0;
        for(j=1; j<i; ++j)
            if(v[j]<v[i])
            {
                if(d[j]==p)
                    nr[i]+=nr[j];
                else
                if(d[j]>p)
                {
                    p=d[j];
                    nr[i]=nr[j];
                }
            }
        if(nr[i]==0)
            nr[i]=1;
        nr[i]%=mod;
        d[i]=p+1;
        mx=max(mx,d[i]);
    }
    for(i=1; i<=n; ++i)
        if(d[i]==mx)
            ans+=nr[i];
    ans%=mod;
    fout<<mx<<'\n'<<ans;
}
