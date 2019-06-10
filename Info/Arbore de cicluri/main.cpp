#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define nmax (int)1e5+10

ifstream fin("arbciclu.in");
ofstream fout("arbciclu.out");

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    int t;

    fin>>t;
    while(t--)
    {
        set <pair<int,int> > edges;
        vector <int> v[nmax];
        int grd[nmax];
        memset(grd, 0, sizeof(grd));
        queue <int> q;

        int n,m;

        fin>>n>>m;
        for(int i=1; i<=m; ++i)
        {
            int a,b;
            fin>>a>>b;
            if(a>b)
                swap(a,b);
            edges.insert(mp(a,b));
            v[a].push_back(b);
            v[b].push_back(a);
            ++grd[a],++grd[b];
        }
        if(n<=2)
        {
            fout<<"NO\n";
            continue;
        }
        for(int i=1; i<=n; ++i)
            if(grd[i]==2)
                q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            if(grd[node]!=2)
                continue;
            --n;
            int a,b;
            a=b=0;
            for(auto it:v[node])
                if(grd[it])
                {
                    if(a)
                        b=it;
                    else
                        a=it;
                }
            if(a>b)
                swap(a,b);
            grd[node]=0;
            if(edges.find(mp(a,b))==edges.end())
                edges.insert(mp(a,b)),v[a].push_back(b),v[b].push_back(a);
            else
            {
                if(--grd[a]==2)
                    q.push(a);
                if(--grd[b]==2)
                    q.push(b);
            }
        }
        if(n==2)
            fout<<"YES\n";
        else
            fout<<"NO\n";
    }
}
