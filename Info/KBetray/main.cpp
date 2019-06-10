#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

ifstream fin("kbetray.in");
ofstream fout("kbetray.out");

vector <int> mn;
vector <int> mx;
int i,n,k;

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    fin>>n>>k;
    for(i=1; i<=n; ++i)
    {
        int a,b;
        fin>>a>>b;
        if(a>b)
            swap(a,b);
        mn.pb(a);
        mx.pb(b);
    }
    sort(mn.begin(),mn.end());
    sort(mx.begin(),mx.end());
    ll ans = 0;
    for(i=0; i<min(n,k); ++i)
    {
        int j = n-1-i;
        if(mn[j]>mx[i])
        {
            ans += mn[j];
        }
        else break;
    }
    for( ; i<n; ++i)
        ans+=mx[i];
    fout<<ans;
}
