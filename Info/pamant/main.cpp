#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

ifstream fin("pamant.in");
ofstream fout("pamant.out");

#define nmax 100010
#define mp make_pair
#define f first
#define s second

stack <pair<int,int> > q;
vector <int> v[nmax];
int dfn[nmax];
int low[nmax];
int cnt[nmax];
int last[nmax];
vector <int> vul;
vector <int> ans;
int k,nr;

void add(int a,int b)
{
    last[a]=last[b]=++nr;
    ++cnt[a];
    ++cnt[b];
    if(cnt[a]==2)
        vul.push_back(a);
    if(cnt[b]==2)
        vul.push_back(b);
    while(q.top().f!=a || q.top().s!=b)
    {
        if(last[q.top().f]!=nr)
        {
            last[q.top().f]=nr,++cnt[q.top().f];
            if(cnt[q.top().f]==2)
                vul.push_back(q.top().f);
        }
        if(last[q.top().s]!=nr)
        {
            last[q.top().s]=nr,++cnt[q.top().s];
            if(cnt[q.top().s]==2)
                vul.push_back(q.top().s);
        }
        q.pop();
    }
    q.pop();
}

void df(int x)
{
    dfn[x]=low[x]=++k;
    ans.back()=min(ans.back(),x);
    for(auto it:v[x])
    {
        if(dfn[it])
            low[x]=min(low[x],dfn[it]);
        else
        {
            q.push(mp(x,it));
            df(it);
            low[x]=min(low[x],low[it]);
            if(low[it]>=dfn[x])
                add(x,it);
        }
    }
}

int main()
{
    int i,n,m,a,b;
    fin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        fin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1; i<=n; ++i)
        if(!dfn[i])
        {
            k=0;
            ans.push_back(1e9);
            df(i);
        }
    fout<<ans.size()<<'\n';
    for(auto it:ans)
        fout<<it<<' ';
    fout<<'\n'<<vul.size()<<'\n';
    sort(vul.begin(),vul.end());
    for(auto it:vul)
        fout<<it<<' ';
}
