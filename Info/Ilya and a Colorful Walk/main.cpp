#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[300100],c[300100];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n,i,ans;

    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
    }
    i=1;
    ans = 1;
    for(i=1; i<=n; i<<=1);

    for( ; i; i>>=1)
    {
        memset(c, 0, sizeof(c));
        if(i+ans<n)
        {
            int curr = i+ans;
            int nr = 0;
            for(int j=1; j<=n-i-ans; j++)
            {
                if(c[v[j]]==0)
                    c[v[j]]++,nr++;
                if(nr>=2 || v[j]!=v[j+curr])
                {
                    ans+=i;
                    break;
                }
            }
        }
    }
    cout<<ans;
}
