#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

ifstream fin("seti.in");
ofstream fout("seti.out");

#define mp make_pair
#define f first
#define s second

pair<pair<int,int>,int> curr[132000];
char S[132000];
int w[132000];
int v[7][132000];
int n,i;
char a[25];
int q,st,dr,k,m;

int compare(int i,int j)
{
    while(i<q)
    {
        if(a[i]!=S[j])
        {
            if(a[i]<S[j])
                return -1;
            else
                return 1;
        }
        ++i,++j;
    }
    return 0;
}


void bs1(int ls, int ld)
{
    if(ls>ld)
        return ;
    int m = (ls+ld)>>1;
    if(compare(0,w[m])<=0)
    {
        st = m;
        bs1(ls,m-1);
    }
    else
    bs1(m+1,ld);
}

void bs2(int ls, int ld)
{
    if(ls>ld)
        return ;
    int m = (ls+ld)>>1;
    if(compare(0,w[m])>=0)
    {
        dr = m+1;
        bs2(m+1,ld);
    }
    else
    bs2(ls,m-1);
}


int main()
{
    fin>>n;
    n*=64;
    for(i=1; i<=n; ++i)
    {
        fin>>S[i];
    }
    for(i=1; i<=n; ++i)
        v[0][i]=S[i];
    for(k=1; k<6; ++k)
    {
        for(i=1; i<=n; ++i)
            curr[i]=mp(mp(v[k-1][i],v[k-1][i+(1<<(k-1))]),i);
        sort(curr+1,curr+n+1);
        for(i=1; i<=n; ++i)
            if(curr[i].f==curr[i-1].f)
                v[k][curr[i].s]=v[k][curr[i-1].s];
            else
                v[k][curr[i].s]=v[k][curr[i-1].s]+1;
    }
    for(i=1; i<=n; ++i)
        w[i]=curr[i].s;
    fin>>m;
    while(m--)
    {
        fin>>a;
        q = strlen(a);
        st = n+1;
        bs1(1,n);
        dr = 0;
        bs2(1,n);
        fout<<dr-st<<'\n';
    }
}
