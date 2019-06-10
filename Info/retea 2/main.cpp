#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("retea.in");
ofstream fout("retea.out");

#define nmax (int)1e3+10
#define f first
#define s second
#define mp make_pair

priority_queue <pair<double,pair<int,int> >,vector <pair<double,pair<int,int> > >,greater <pair<double,pair<int,int> > > >h;
vector <pair<double,int> > v[nmax];
double d[nmax][11];
bool used[nmax][11];
int n,m,k,i,j;

int main()
{
    fin>>n>>m>>k;
    while(m--)
    {
        int a,b,c;
        fin>>a>>b>>c;
        v[a].push_back(mp(c,b));
        v[b].push_back(mp(c,a));
    }
    for(i=1; i<=n; ++i)
        for(j=0; j<=k; ++j)
            d[i][j]=1e9;
    h.push(mp(0,mp(1,0)));
    d[1][0]=0;
    while(!h.empty())
    {
        int nod = h.top().s.f;
        int curr = h.top().s.s;
        h.pop();
        if(used[nod][curr])
            continue;
        used[nod][curr]=1;
        for(auto it:v[nod])
            for(i=curr; i<=k; ++i)
                if(!used[it.s][curr] && d[nod][curr]+(double)(it.f/(1<<(i-curr)))<d[it.s][i])
                {
                    d[it.s][i]=d[nod][curr]+(double)(it.f/(1<<(i-curr)));
                    h.push(mp(d[it.s][i],mp(it.s,i)));
                }
    }
    fout<<setprecision(4)<<fixed<<d[n][k];
}
