#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("inv.in");
ofstream fout("inv.out");

#define f first
#define s second

#define zeros(x) (x ^ (x-1)) & x

int i,n,res,k,ans;
int aib[100100];
pair<int,int> v[100100];
pair<int,int> w[100100];

void add(int x, int quantity)
{
    int i;

    for (i = x; i <= n; i += zeros(i))
        aib[i] += quantity;
}

int compute(int x)
{
    int i, ret = 0;

    for (i = x; i > 0; i -= zeros(i))
        ret += aib[i];
    return ret;
}

bool cmp1(pair<int,int> a,pair<int,int> b)
{
    return a.f<b.f;
}

bool cmp2(pair<int,int> a,pair<int,int> b)
{
    return a.s<b.s;
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i].f;
        v[i].s=i;
    }
    sort(v+1,v+n+1,cmp1);
    for(i=1; i<=n; ++i)
        if(v[i].f!=v[i-1].f)
        {
            w[i].f=++k;
            w[i].s=v[i].s;
        }
        else
        {
            w[i].f=k;
            w[i].s=v[i].s;
        }
    sort(w+1,w+n+1,cmp2);
    for(i=1; i<=n; ++i)
    {
        ans+=compute(n)-compute(w[i].f);
        add(w[i].f,1);
        ans%=9917;
    }
    fout<<ans%9917;
}
