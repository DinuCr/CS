#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("fotbal2.in");
ofstream fout("fotbal2.out");

#define nmax 50010
#define mp make_pair
#define f first
#define s second

vector <pair<int,int> > v[nmax];
vector <pair<int,int> > ans;

void sterge(int a,int b)
{
    for(int i=0; i<v[a].size(); ++i)
        if(v[a][i].f==b)
        {
            swap(v[a][i],v[a][v[a].size()-1]);
            v[a].pop_back();
        }
}

void fleury(int x)
{
    while(v[x].size())
    {
        sterge(v[x].back().s,v[x].back().f);
        if(v[x].back().f!=0)
        {
            ans.push_back(mp(v[x].back().f,v[x].back().s));
        }
        int a = v[x].back().s;
        v[x].pop_back();
        fleury(a);
    }
}

int main()
{
    int n,m,i,a,b;
    fin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        fin>>a>>b;
        v[a].push_back(mp(i,b));
        v[b].push_back(mp(i,a));
    }
    int ok = 1;
    for(i=1; i<=n; ++i)
        if(v[i].size()&1)
        {
            ok=0;
            v[0].push_back(mp(m+i,i));
            v[i].push_back(mp(m+i,0));
        }
    for(i=0; i<=n; ++i)
        while(v[i].size())
            fleury(i);
    sort(ans.begin(),ans.end());
    if(ok)
        fout<<0<<'\n';
    else
        fout<<2<<'\n';
    for(auto it:ans)
        fout<<it.s<<'\n';
}
