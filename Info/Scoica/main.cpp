#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define nmax (int)1e6+10

const int mod = 1e9+7;

vector <int> v[nmax];
vector <int> r;
int w[nmax];
int ord[nmax];
int d[nmax];
int position[nmax];

inline ll modulo(ll x)
{
    if(x>=mod)
        x%=mod;
    return x;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n,m,p,i;

    cin>>n>>m>>p;
    for(i=1; i<=p; ++i)
        cin>>ord[i];

    ++p;
    ord[p]=n;

    for(i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        w[b]++;
    }
    for(i=1; i<=n; i++)
        if(!w[i])
            r.push_back(i);
    for(i=0; i<r.size(); ++i)
    {
        for(int j=0;j<v[r[i]].size();++j)
        {
            w[v[r[i]][j]]--;
            if(!w[v[r[i]][j]])
                r.push_back(v[r[i]][j]),position[v[r[i]][j]]=r.size();
        }
    }
    int curr = 0;
    d[1]=1;
    for(i=1; i<=p; ++i)
    {
        int j;
        for(j=curr; r[j]!=ord[i]; ++j)
            for(auto it:v[r[j]])
                if(position[it]<=position[ord[i]])
                    d[it]=modulo(d[it]+d[r[j]]);
        curr = j;
    }
    cout<<d[n];

}
