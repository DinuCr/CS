#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("camionas.in");
ofstream fout("camionas.out");

#define nmax (int)(5*1e4+10)
#define mp make_pair
#define f first
#define s second

priority_queue <pair<int,int>, vector <pair<int,int> >,greater <pair<int,int> > >h;
vector <pair<int,int> > v[nmax];
int d[nmax];
int n,m,g,i;

int main()
{
    fin>>n>>m>>g;
    for(i=1; i<=m; ++i)
    {
        int a,b,c;
        fin>>a>>b>>c;
        v[a].push_back(mp(c,b));
        v[b].push_back(mp(c,a));
    }
    for(i=2; i<=n; ++i)
        d[i]=1e9;
    h.push(mp(0,1));
    while(!h.empty())
    {
        int nod = h.top().s;
        h.pop();
        for(auto it:v[nod])
            if(d[nod]+(g>it.f)<d[it.s])
                d[it.s]=d[nod]+(g>it.f),h.push(mp(d[it.s],it.s));
    }
    fout<<d[n];
}
