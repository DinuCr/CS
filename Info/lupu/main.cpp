#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

ifstream fin("lupu.in");
ofstream fout("lupu.out");

#define nmax 100100
#define f first
#define s second
#define mp make_pair

priority_queue <int> h;
pair <int,int> v[nmax];
int ok,n,i,x,a,b,l,j,tmax;
long long ans;

inline bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.f>b.f;
}

int main()
{
    fin>>n>>x>>l;
    for(i=1; i<=n; ++i)
    {
        fin>>a>>b;
        if(a<=x)
            a=(x-a)/l+1;
        else
            a=0;
        tmax=max(tmax,a);
        v[i]=mp(a,b);
    }
    sort(v+1,v+n+1,cmp);
    j=1;
    for(i=tmax; i>0; --i)
    {
        for( ; j<=n && v[j].f==i; ++j)
        {
                h.push(v[j].s);
        }
        if(!h.empty())
        {
            ans+=h.top();
            h.pop();
        }
    }
    fout<<ans;
}
