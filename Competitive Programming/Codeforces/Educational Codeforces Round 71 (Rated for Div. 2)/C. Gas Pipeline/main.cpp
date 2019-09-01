#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

char v[201000];
ll w[201000];
ll d[201000][2];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    ll t,n,a,b,i;

    cin>>t;

    while(t--)
    {
        cin>>n>>a>>b;
        for(i=1; i<=n; ++i)
            cin>>v[i];
        memset(d, 0, sizeof(d));
        memset(w, 0, sizeof(w));
        d[0][1]=1e12;
        for(i=1; i<=n; ++i)
            if(v[i]=='1')
                w[i-1]=1,w[i]=1;
        for(i=1; i<=n; ++i)
            if(w[i])
            {
                d[i][0]=1e15;
                d[i][1]=min(d[i-1][1]+a+b*2,d[i-1][0]+2*a+2*b);
            }
            else
            {
                d[i][0]=min(d[i-1][0]+a+b,d[i-1][1]+2*a+b);
                d[i][1]=min(d[i-1][1]+a+b*2,d[i-1][0]+2*a+2*b);
            }
        cout<<min(d[n][0],d[n][1]+a-b)+b<<'\n';
    }
}
