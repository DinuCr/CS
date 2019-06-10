#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("schi.in");
ofstream fout("schi.out");

#define nmax 30100
#define zeros(x) (x&(x^(x-1)))

int n,v[nmax],ans[nmax],y,i,t[nmax];

void add(int poz,int x)
{
    for( ; poz <=n; poz+=zeros(poz))
        v[poz]+=x;
}

int compute(int poz)
{
    int rez = 0;
    for( ; poz>0; poz-=zeros(poz))
        rez+=v[poz];
    return rez;
}

void bs(int ls,int ld,int x)
{
    if(ls>ld)
        return;
    int m = (ls+ld)>>1;
    if(compute(m)>=x)
    {
        y = m;
        bs(ls,m-1,x);
    }
    else
    bs(m+1,ld,x);
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>t[i];
        add(i,1);
    }
    for(i=n; i>0; --i)
    {
        bs(1,n,t[i]);
        int m = y;
        ans[m]=i;
        add(m,-1);
    }
    for(i=1; i<=n; ++i)
        fout<<ans[i]<<'\n';
}
