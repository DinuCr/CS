#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define mp make_pair
#define f first
#define s second

pair<int,int> v[1100];
int n,j,i;
int d[1100];

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.s==b.s)
        return (a.f+a.s)/2 < (b.f+b.s)/2;
    return a.s<b.s;
}

bool cmp2(pair<int,int> a,pair<int,int> b)
{
    if(a.s==b.s)
        return (a.f+a.s)/2 > (b.f+b.s)/2;
    return a.s<b.s;
}

bool cmp3(pair<int,int> a,pair<int,int> b)
{
    if(a.s+a.f==b.s+b.s)
        return a.s<b.s;
    return (a.f+a.s)/2 < (b.f+b.s)/2;
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        int a,b;
        fin>>a>>b;
        v[i]=mp(a-b,a+b);
    }
    sort(v+1,v+n+1,cmp);
    int nr = 0;

    d[1]=1;
    nr=1;
    for(i=2; i<=n; ++i)
    {
        for(j=1; j<i; ++j)
            if(v[j].s < (v[i].s+v[i].f)/2 && (v[j].s+v[j].f)/2<v[i].f)
                d[i]=max(d[i],d[j]+1);
        nr=max(d[i],nr);
    }
    sort(v+1,v+n+1,cmp2);
    memset(d,0,sizeof(d));
    d[1]=1;
    int nr2=1;
    for(i=2; i<=n; ++i)
    {
        for(j=1; j<i; ++j)
            if(v[j].s < (v[i].s+v[i].f)/2 && (v[j].s+v[j].f)/2<v[i].f)
                d[i]=max(d[i],d[j]+1);
        nr2=max(d[i],nr);
    }

    sort(v+1,v+n+1,cmp3);
    memset(d,0,sizeof(d));
    d[1]=1;
    int nr3=1;
    for(i=2; i<=n; ++i)
    {
        for(j=1; j<i; ++j)
            if(v[j].s < (v[i].s+v[i].f)/2 && (v[j].s+v[j].f)/2<v[i].f)
                d[i]=max(d[i],d[j]+1);
        nr3=max(d[i],nr);
    }

    fout<<max(nr,max(nr2,nr3));
}
