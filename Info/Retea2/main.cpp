#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

ifstream fin("retea2.in");
ofstream fout("retea2.out");

vector <pair<int,int> > v;
vector <pair<int,int> > w;
ll d[2010];

inline ll dist(pair<int,int> a,pair<int,int> b)
{
    return (1LL*(a.f-b.f)*(a.f-b.f)+1LL*(a.s-b.s)*(a.s-b.s));
}

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    int n,m,i,j,a,b;

    set <int> not_used;

    fin>>n>>m;
    for(i=1; i<=n; ++i)
    {
        fin>>a>>b;
        w.pb(mp(a,b));
    }
    for(i=1; i<=m; ++i)
    {
        fin>>a>>b;
        v.pb(mp(a,b));
        not_used.insert(i-1);
    }
    for(i=0; i<m; ++i)
        d[i]=1e15;
    for(i=0; i<v.size(); ++i)
        for(j=0; j<w.size(); ++j)
            d[i]=min(d[i],dist(v[i],w[j]));
    double ans = 0;
    while(m--)
    {
        ll curr = 1e15;
        int node = 0;
        for(set<int> ::iterator it=not_used.begin(); it!=not_used.end(); ++it)
            if(d[*it]<curr)
                curr=d[*it],node=*it;
        not_used.erase(node);
        ans+=(double)sqrt(curr);
        for(i=0; i<v.size(); ++i)
            if(not_used.count(i))
                d[i]=min(d[i],dist(v[i],v[node]));
    }
    fout<<setprecision(6)<<fixed<<ans;
}
