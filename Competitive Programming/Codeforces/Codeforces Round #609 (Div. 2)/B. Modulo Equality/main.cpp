#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int nmax = 2100;

int a[nmax];
int b[nmax];
int n,m;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

    cin>>n>>m;
    for(int i=1; i<=n; ++i)
        cin>>a[i];
    for(int i=1; i<=n; ++i)
        cin>>b[i];

    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    int ans = m+1;
    for(int i=1; i<=n; ++i)
	{
	    int curr;
	    if(b[i]>=a[1])
            curr=b[i]-a[1];
        else
            curr=m-a[i]+b[i];
        int ok = 1;
        int k = i;
        for(int j=1; j<=n; ++j)
            if((a[j]+curr)%m!=b[k])
            {
                ok=0;
                break;
            }
            else
            {
                ++k;
                if(k==n+1)
                    k=1;
            }
        if(ok)
            ans=min(ans, curr);
    }
    cout<<ans;
}
