#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>

using namespace std;

ifstream fin("cuburi3.in");
ofstream fout("cuburi3.out");

#define f first
#define s second
#define nmax 4500

pair <int,pair<int,int> > v[nmax];
int d[nmax];
int l[nmax];
int ans[nmax];
int n,i,mx,j,p,poz;

bool compare(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b)
{
    return a.f>b.f;
}

int main()
{
    fin>>n;
    int a,b;
    for(i=1; i<=n; ++i)
    {
        fin>>a>>b;
        v[i]=make_pair(a,make_pair(b,i));
    }
    a=0;
    sort(v+1,v+n+1,compare);
    for(i=1; i<=n; ++i)
    {
        mx=0;
        p=0;
        for(j=1; j<i; ++j)
            if(v[j].s.f>=v[i].s.f)
            {
                if(l[j]>=mx)
                {
                   mx=l[j];
                   p=j;
                }
            }
        d[i]=d[p]+1;
        l[i]=mx+v[i].f;
        ans[i]=p;
        if(l[i]>a)
        {
            a=l[i];
            poz=i;
        }
    }
    int k=0;
    fout<<d[poz]<<' '<<a<<'\n';
    while(poz!=0)
    {
        ++k;
        d[k]=v[poz].s.s;
        poz=ans[poz];
    }
    for(i=k; i>0; --i)
    fout<<d[i]<<'\n';
}
