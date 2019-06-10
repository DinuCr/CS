#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define nmax (int) 1e5+10

ifstream fin("arbore5.in");
ofstream fout("arbore5.out");

vector <int> v[nmax];
int curr[nmax];
int ans = 0;

void df(int x,int t)
{
    for(auto it:v[x])
        if(it!=t)
            df(it,x),curr[x]+=curr[it];
    if(x!=0 && curr[x]&1)
        ++ans;
}

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    int n,m,i;

    fin>>n>>m;
    for(i=1; i<n; ++i)
    {
        int a,b;
        fin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    while(m--)
    {
        int a,b;
        fin>>a>>b;
        ++curr[a],++curr[b];
    }
    df(1,0);
    fout<<n-ans-1;
}
