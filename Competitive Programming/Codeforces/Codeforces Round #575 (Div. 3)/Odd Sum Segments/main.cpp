#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int n,q,k,i,v[200100];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>q;

    while(q--)
    {
        cin>>n>>k;
        int cnt = 0;
        for(i=1; i<=n; ++i)
        {
            int x;
            cin>>x;
            if(x&1)
                v[i]=1,cnt++;
            else
                v[i]=0;
        }
        if((cnt-k)%2==1 || cnt-k<0)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            --k;
            for(i=1; i<=n && k; ++i)
                if(v[i])
                    cout<<i<<' ',k--;
            cout<<n<<'\n';
        }
    }
}
