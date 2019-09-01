#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[500100];
int d[1005][1005];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int q,a,b,t,i;

    cin>>q;

    while(q--)
    {
        cin>>t>>a>>b;

        if(t==1)
        {
            v[a]+=b;
            for(i=1; i<=1000; ++i)
                d[i][a%i]+=b;
        }
        else
        {
            if(a<=1000)
                cout<<d[a][b]<<'\n';
            else
            {
                ll ans = 0;
                for(i=b; i<=500000; i+=a)
                    ans+=v[i];
                cout<<ans<<'\n';
            }
        }
    }
}
