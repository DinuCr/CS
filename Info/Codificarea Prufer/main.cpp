#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("prufer.in");

#define nmax 100
#define mp make_pair
#define f first
#define s second
#define pb push_back

priority_queue<pair<int,int> ,vector <pair<int,int> >,greater<pair<int,int> > >h;
vector <int> v[100];
int viz[nmax];
int ans[100];
int n,m,i,k;

void sterge(int x,int nod)
{
    for(int i=0; i<v[x].size(); ++i)
        if(v[x][i]==nod)
        {
            swap(v[x][i],v[x][v[x].size()-1]);
            v[x].pop_back();
            return ;
        }
}

int main()
{
    fin>>n>>m;
    while(m--)
    {
        int x,y;
        fin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(i=1; i<=n; ++i)
        h.push(mp(v[i].size(),i));
    while(!h.empty())
    {
        int nod = h.top().s;
        if(v[nod].size()!=h.top().f)
        {
            h.pop();
            continue;
        }
        h.pop();
        if(v[nod].size()==1)
        {
            ans[++k]=v[nod][0];
            sterge(v[nod][0],nod);
            h.push(mp(v[v[nod][0]].size(),v[nod][0]));
        }
    }
    for(i=1; i<=k; ++i)
        cout<<ans[i]<<' ';
}
