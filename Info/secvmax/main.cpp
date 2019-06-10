#include <iostream>
#include <stack>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("secvmax.in");
ofstream fout("secvmax.out");
#define f first
#define s second
#define mp make_pair
#define nmax 100100
stack <int> q;
int v[nmax];
int dr[nmax];
int st[nmax];
pair <int,int> ans[nmax];
int n,m,i;
inline bool cmp(const pair <int,int> &a,const pair<int,int> &b)
{
    if(a.f==b.f)
        return a.s>b.s;
    return a.f<b.f;
}
int bs(int s,int d,int x)
{
    if(s>d)
        return d;
    int m = (s+d)/2;
    if(ans[m].f==x)
        return m;
    if(ans[m].f>x)
        return bs(s,m-1,x);
    return bs(m+1,d,x);
}
int inf;
int main()
{
    fin>>n>>m;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
        inf=max(inf,v[i]);
    }
    ++inf;
    v[0]=inf;
    v[n+1]=inf;
    q.push(0);
    for(i=1; i<=n; ++i)
    {
        while(v[i]>=v[q.top()])
            q.pop();
        st[i]=q.top();
        q.push(i);
    }
    while(!q.empty())
        q.pop();
    q.push(n+1);
    for(i=n; i>0; --i)
    {
        while(v[i]>=v[q.top()])
            q.pop();
        dr[i]=q.top();
        q.push(i);
    }
    for(i=1; i<=n; ++i)
        ans[i]=mp(v[i],(dr[i]-st[i]-1));
    sort(ans+1,ans+n+1,cmp);
    for(i=1; i<=n; ++i)
        ans[i].s=max(ans[i].s,ans[i-1].s);
    int x;
    for(i=1; i<=m; ++i)
    {
        fin>>x;
        int p = bs(1,n,x);
        fout<<ans[p].s<<'\n';
    }
}
