#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("vmin.in");
ofstream fout("vmin.out");

#define nmax 100100
#define f first
#define s second

pair <pair<int,int> ,int> v[nmax];
pair <pair<int,int> ,int > q[nmax];

int n,m,i,k,t;

bool cmp(const pair<pair<int,int>,int>  &a,const pair<pair<int,int>,int> &b)
{
    if(a.f.f==b.f.f)
        return a.f.s > b.f.s;
    return a.f.f > b.f.f;
}

inline bool lower(const pair<pair<int,int>,int>  &a,const pair<pair<int,int>,int>  &b,const pair<pair<int,int>,int>  &c)
{
    if( 1LL * ( c.f.s - b.f.s ) * ( a.f.f - b.f.f ) < 1LL * ( b.f.s - a.f.s ) * ( b.f.f - c.f.f ) )
        return 1;
    return 0;
}

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        fin>>v[i].f.f>>v[i].f.s,
        v[i].s=i;

    sort(v+1,v+n+1,cmp);

    q[1]=v[1],k=1;

    if(n>1)
        q[2]=v[2],k=2;

    for(i=3; i<=n; ++i)
    {
        q[++k]=v[i];
        while(k>2 && lower(q[k-2],q[k-1],q[k]))
            q[k-1]=q[k],--k;
    }

    int poz = 1;

    while(m--)
    {
        fin>>t;
        while(poz<k && 1LL*q[poz].f.f*t+q[poz].f.s>1LL*q[poz+1].f.f*t+q[poz+1].f.s)
            ++poz;
        fout<<q[poz].s<<' ';
    }
}
