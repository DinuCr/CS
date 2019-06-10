#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ll ans;
int v[200010];
int n,i,j;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        v[i]=abs(v[i]);
    }
    sort(v+1,v+n+1);
    for(i=1; i<=n; ++i)
    {
        int curr = i;
        for(j=1; j<=n; j<<=1);

        for( ; j>0; j>>=1)
        if(curr+j<=n)
        {
            if(v[curr+j]-v[i]<=v[i])
                curr+=j;
        }
        ans+=curr-i;
    }
    cout<<ans;
}
