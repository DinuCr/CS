#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int t,n,v[155000],i;

    cin>>t;


    while(t--)
    {
        cin>>n;
        int cnt = 0;
        memset(v,0,sizeof(v));
        for(i=1; i<=n; ++i)
            cin>>v[i];
        int mn = 1e7;
        for(i=n; i>0; --i)
        {
            mn=min(v[i],mn);
            if(v[i]>mn)
                cnt++;
        }
        cout<<cnt<<'\n';
    }
}
