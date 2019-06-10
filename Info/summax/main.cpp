#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream fin("summax.in");
ofstream fout("summax.out");

#define nmax 2010
#define inf 2000000000
#define ll long long

int d[nmax*nmax/2];
int nr[nmax*nmax/2];
int n,p,st,dr;

inline int ch(int x,int y)
{
    return (x-1)*x/2+y;
}

inline ll mod(ll x)
{
    if(x>inf)
        return inf+1;
    return x;
}

void drum(int m)
{
    int x=1,y=1,curr=0;
    while(x!=n)
    {
        fout<<y<<' ';
        if(d[ch(x+1,y)]==d[ch(x+1,y+1)])
        {
            if(curr+nr[ch(x+1,y)]<m)
                curr+=nr[ch(x+1,y)],++x,++y;
            else
                ++x;
        }
        else
        if(d[ch(x+1,y)]>d[ch(x+1,y+1)])
            ++x;
        else
            ++x,++y;
    }
    fout<<y<<'\n';
}

int main()
{
    int i,j;
    fin>>p>>n>>st>>dr;
    for(i=1; i<=n; ++i)
        for(j=1; j<=i; ++j)
            fin>>d[ch(i,j)];
    for(i=1; i<=n; ++i)
        nr[ch(n,i)]=1;
    for(i=n-1; i>0; --i)
        for(j=1; j<=i; ++j)
        {
            d[ch(i,j)]+=max(d[ch(i+1,j)],d[ch(i+1,j+1)]);
            if(d[ch(i+1,j)]>d[ch(i+1,j+1)])
                nr[ch(i,j)]=nr[ch(i+1,j)];
            else
            if(d[ch(i+1,j)]<d[ch(i+1,j+1)])
                nr[ch(i,j)]=nr[ch(i+1,j+1)];
            else
                nr[ch(i,j)]=mod(1LL*nr[ch(i+1,j)]+1LL*nr[ch(i+1,j+1)]);
        }
    if(p==1)
    {
        fout<<nr[ch(1,1)];
    }
    else
    {
        for(i=st; i<=dr; ++i)
            drum(i);
    }
}
