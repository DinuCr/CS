#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[200010];
int t,n,k,i;

int dist(int i, int j, int n, int pos)
{
    return max(abs(pos-v[i]),abs(pos-v[j]));
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1; i<=n; ++i)
            cin>>v[i];
        ++k;
        int mn = 2e9;
        i = 1;
        int j = max(k,1);
        int ans = 0;
        for( ; j<=n; ++j,++i)
        {
            int pos = (v[i]+v[j])/2;
            if(dist(i,j,n,pos)<mn)
            {
                mn = dist(i,j,n,pos);
                ans = pos;
            }
            pos = (v[i]+v[j]+1)/2;
            if(dist(i,j,n,pos)<mn)
            {
                mn = dist(i,j,n,pos);
                ans = pos;
            }
        }
        cout<<ans<<'\n';
    }
}
