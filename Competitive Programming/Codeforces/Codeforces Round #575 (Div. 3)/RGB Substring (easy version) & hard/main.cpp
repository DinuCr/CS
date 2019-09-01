#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

string s;
char v[200100];
char base[5];
int d1[200100],d2[200100],d3[200100];
int n,q,k,i;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>q;
    base[0]='R';
    base[1]='G';
    base[2]='B';

    while(q--)
    {
        cin>>n>>k;
        cin>>s;
        for(i=1; i<=n; ++i)
            v[i]=s[i-1];
        for(i=1; i<=n; ++i)
        {
            d1[i]=d1[i-1]+(v[i]==base[i%3]);
            d2[i]=d2[i-1]+(v[i]==base[(i+1)%3]);
            d3[i]=d3[i-1]+(v[i]==base[(i+2)%3]);
        }
        int ans = 0;
        for(i=k; i<=n; ++i)
        {
            ans=max(ans,d1[i]-d1[i-k]);
            ans=max(ans,d2[i]-d2[i-k]);
            ans=max(ans,d3[i]-d3[i-k]);
        }
        cout<<k-ans<<'\n';
    }
}
