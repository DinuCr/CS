#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("apm2.in");
ofstream fout("apm2.out");

#define mp make_pair
#define f first
#define s second
#define nmax (int) 1e5+10

pair<int,pair<int,int> > v[nmax];
int t[(int) 1e4+10];
int ans[(int)1e3+10];

int root(int x)
{
    if(!t[x])
        return x;
    t[x]=root(t[x]);
    return t[x];
}

int main()
{
    int n,m,q;
    fin>>n>>m>>q;
    for(int i=1; i<=m; ++i)
        fin>>v[i].s.f>>v[i].s.s>>v[i].f;
    vector <pair<int,int> > w;
    int q2=q;
    while(q2--)
    {
        int a,b;
        fin>>a>>b;
        w.push_back(mp(a,b));
    }
    sort(v+1,v+m+1);
    for(int i=1; i<=m; ++i)
    {
        if(v[i].f!=v[i-1].f)
        {
            for(int j=0; j<w.size(); ++j)
                if(root(w[j].f)!=root(w[j].s))
                    ans[j]=v[i].f-1;
        }
        if(root(v[i].s.f)!=root(v[i].s.s))
            t[root(v[i].s.f)]=root(v[i].s.s);
    }
    for(int i=0; i<q; ++i)
        fout<<ans[i]<<'\n';
}
