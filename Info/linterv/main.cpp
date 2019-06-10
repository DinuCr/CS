#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("linterv.in");
ofstream fout("linterv.out");

#define f first
#define s second
#define mp make_pair

pair<int,int> v[5500];
int urm[5500];
int n,i,t,a,b,l,ans;

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
    if(a.f==b.f)
        return a.s>b.s;
    return a.f<b.f;
}

int main()
{
    fin>>t;
    for( ;t--; )
    {
        fin>>n;
        for(i=0; i<n; ++i)
        {
            fin>>a>>b;
            if(b<a)
                swap(a,b);
            v[i]=mp(a,b);
        }
        sort(v,v+n,cmp);
        a=0;
        for(i=0; i<n; )
        {
            while(v[i].f==v[i+1].f)
                ++i;
            ++i;
            urm[a]=i;
            a=i;
        }
        l=v[0].s;
        ans=v[0].s-v[0].f;
        for(i=urm[0]; i<n; i=urm[i])
        {
            if(l<v[i].f)
                ans+=v[i].s-v[i].f;
            else
            if(l<v[i].s)
                ans+=v[i].s-l;
            l=max(l,v[i].s);
        }
        fout<<ans<<'\n';
    }
}
