#include <iostream>
#include <fstream>
#include <algorithm>
#include <algorithm>

using namespace std;

ifstream fin("calafat.in");
ofstream fout("calafat.out");

#define mp make_pair
#define f first
#define s second
#define nmax 200010
#define ll long long

#define zeros(x) ((x^(x-1)) &x)
vector <pair<pair<int,int>,pair<int,ll> > >q;
int v[nmax];
int last[nmax];
ll ans[nmax];
int n;

void add(int p,int x)
{
    for( ; p<=n; p+=zeros(p))
        ans[p]+=x;
}

long long compute(int p)
{
    long long rez = 0;
    for( ; p>0; p-=zeros(p))
        rez+=ans[p];
    return rez;
}

bool cmp1(const pair<pair<int,int>,pair<int,ll> > &a,const pair<pair<int,int>,pair<int,ll> > &b)
{
    return a.f.s<b.f.s;
}

bool cmp2(const pair<pair<int,int>,pair<int,ll> > &a,const pair<pair<int,int>,pair<int,ll> > &b)
{
    return a.s.f<b.s.f;
}


int main()
{
    int i,a,b,m;
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    for(i=1; i<=m; ++i)
    {
        fin>>a>>b;
        q.push_back(mp(mp(a,b),mp(i,0)));
    }
    sort(q.begin(),q.end(),cmp1);
    int p = 0;
    for(i = 0; i<q.size(); ++i)
    {
        while(p<q[i].f.s)
        {
            ++p;
            if(last[v[p]]!=0)
                add(last[v[p]],p-last[v[p]]);
            last[v[p]]=p;
        }
        q[i].s.s=compute(q[i].f.s)-compute(q[i].f.f-1);
    }
    sort(q.begin(),q.end(),cmp2);
    for(auto it:q)
        fout<<it.s.s<<'\n';
}
