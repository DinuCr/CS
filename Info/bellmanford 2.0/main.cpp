#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

#define nmax (int)1e5+10
#define mp make_pair
#define f first
#define s second

priority_queue <pair<int,int> ,vector <pair<int,int> >, greater <pair<int,int> > >h;
vector <pair<int,int> > v[nmax];
int d[nmax];
int used[nmax];
int n,m;

int main()
{
    fin>>n>>m;
    while(m--)
    {
        int a,b,c;
        fin>>a>>b>>c;
        v[a].push_back(mp(c,b));
    }
    for(int i=2; i<=n; ++i)
        d[i]=2e9;
    h.push(mp(0,1));
    while(!h.empty())
    {
        int nod = h.top().s;
        h.pop();
        for(auto it:v[nod])
            if(d[nod]+it.f<d[it.s])
            {
                d[it.s]=d[nod]+it.f;
                h.push(mp(d[it.s],it.s));
                if(++used[it.s]==n)
                {
                    fout<<"Ciclu negativ!";
                    return 0;
                }
            }
    }
    for(int i=2; i<=n; ++i)
        fout<<d[i]<<' ';
}
