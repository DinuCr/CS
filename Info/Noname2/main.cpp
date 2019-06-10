#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ifstream fin("noname2.in");
ofstream fout("noname2.out");

#define nmax (int) 1e5+10

int v[nmax];
ll d[nmax];
int n,k;

ll compute(int l,int r)
{
    int m = (l+r)>>1;
    return (v[m]*(m-l)-d[m-1]+d[l-1]) + (d[r]-d[m]-v[m]*(r-m));
}

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    int i;

    fin>>n>>k;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
    }
    sort(v+1,v+n+1);
    for(i=1; i<=n; ++i)
        d[i]=d[i-1]+v[i];
    int l = 0, ans = 0;
    for(int r = 1; r<=n; ++r)
    {
        while(compute(l,r)>k)
            ++l;
        ans = max(ans,r-l+1);
    }
    fout<<ans;
}
