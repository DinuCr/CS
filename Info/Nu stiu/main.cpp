#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define nmax (int)1e4+10

ifstream fin("nustiu.in");
ofstream fout("nustiu.out");

vector <int> v[nmax];
int d[nmax];
int mx[nmax];

void compute(int x,int a)
{
    for(auto it:v[x])
        if(it!=a)
            compute(it,x),d[x]+=d[it],mx[x]=max(mx[x],d[it]);
    d[x]+=1;
}

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    string no_ans = "NIMIC\n";

    int t,n,m,i;

    fin>>t;
    while(t--)
    {
        fin>>n;
        for(i=1; i<=n; ++i)
            v[i].clear();
        for(i=1; i<n; ++i)
        {
            int a,b;
            fin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        memset(d, 0, sizeof(d));
        memset(mx, 0, sizeof(mx));
        compute(1,0);
        bool ok = false;
        for(i=1; i<=n; ++i)
            if(n-d[i]<=(n>>1) && mx[i]<=(n>>1))
                fout<<i<<'\n',ok=true;
        if(!ok)
                fout<<no_ans;
    }
}
