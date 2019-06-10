#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream fin("piete.in");
ofstream fout("piete.out");

int v[15][15];
int r[200];
int val[15];
int i,j,m,s,f,n,nr,ok;

bool cmp(int a,int b)
{
    return a>b;
}

inline int maxim(int a,int b)
{
    if(b>a)
        return b;
    return a;
}

int cumpar(int x,int y,int sum)
{
    int i,j;
    for(i=1; i<=m; ++i)
        val[i]=v[y][i]-v[x][i];

    int ans = 0;
    memset(r, 0, sizeof(r));
    r[0]=1;
    for(i=1; i<=m; ++i)
        if(val[i]>0)
        {
            for(j=sum; j>=0; --j)
                if(r[j] && j+v[x][i]<=sum)
                {
                    r[j+v[x][i]]=maxim(r[j]+val[i],r[j+v[x][i]]);
                    ans=maxim(ans,r[j+v[x][i]]);
                }
        }
    return sum+ans-1;
}

void bkt(int sum)
{
    if(sum>=f)
        return;
    int i,j,mx=0;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            if(i!=j)
            {
                mx=maxim(mx,cumpar(i,j,sum));
            }
    ++nr;
    if(mx<=sum)
    {
        fout<<-1;
        ok=0;
        return;
    }
    bkt(mx);
}

int main()
{
    fin>>n>>m>>s>>f;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            fin>>v[i][j];
    ok=1;
    bkt(s);
    if(ok)
        fout<<nr;
}
