#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("banana.in");
ofstream fout("banana.out");

#define mp make_pair
#define pb push_back
#define f first
#define s second

vector <pair<int,int> > v[10005];
int t[16005];
int d[16005];
int n,k,i,x,y,ans;

int abs(int x)
{
    if(x<0)
        return -x;
    return x;
}

int root(int x)
{
    if(!t[x])
        return x;
    t[x]=root(t[x]);
    return t[x];
}

int main()
{
    fin>>n>>k;
    for(i=1; i<=n; ++i)
    {
        fin>>x>>y;
        v[x].pb(mp(y,i));
        d[i]=1;
    }
    for(i=1; i<=10000; ++i)
        if(v[i].size())
        {
            for(int j=0; j<v[i].size(); ++j)
            {
                for(int k=j+1; k<v[i].size(); ++k)
                    if(abs(v[i][j].f-v[i][k].f)<2 && root(v[i][j].s)!=root(v[i][k].s))
                    {
                        d[root(v[i][k].s)]+=d[root(v[i][j].s)];
                        d[root(v[i][j].s)]=0;
                        t[root(v[i][j].s)]=root(v[i][k].s);
                    }
                for(auto it:v[i+1])
                {
                    if(it.f==v[i][j].f && root(v[i][j].s)!=root(it.s))
                    {
                        d[root(v[i][j].s)]+=d[root(it.s)];
                        d[root(it.s)]=0;
                        t[root(it.s)]=root(v[i][j].s);
                    }
                }
            }
        }
    sort(d+1,d+n+1);
    for(i=n; i>n-k; --i)
        ans+=d[i];
    fout<<ans;
}
