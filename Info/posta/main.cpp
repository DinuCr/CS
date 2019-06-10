#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("posta2.in");
ofstream fout("posta2.out");

#define nmax 100010
#define f first
#define s second
#define mp make_pair

vector <pair<int,int> > v[nmax];
vector <int> q;
vector <int> curr;
int ok[nmax];
int inc[nmax];
int val[nmax];
long long cost;

void df(int x,int t)
{
    if(t!=0)
        inc[x]=1;
    for(auto it:v[x])
        if(t!=it.f)
        {
            df(it.f,x);
            ok[x]|=ok[it.f];
            if(ok[it.f])
                cost+=it.s<<1,inc[x]++;
        }
    if(ok[x])
        cost+=1LL*(inc[x]-1)*val[x],curr.push_back(x);
}

int main()
{
    int a,b,cst,n,m,i;
    fin>>n>>m;
    for(i=1; i<n; ++i)
    {
        fin>>a>>b>>cst;
        v[a].push_back(mp(b,cst));
        v[b].push_back(mp(a,cst));
    }
    for(i=1; i<=n; ++i)
        fin>>val[i];
    for(i=1; i<=m; ++i)
    {
        fin>>a;
        ok[a]=1;
        q.push_back(a);
    }
    df(q.front(),0);
    long long ans = 1e18;
    for(auto it:curr)
        ans = min(ans,cost-1LL*(inc[it]-1)*1LL*val[it]);
    fout<<ans;
}
