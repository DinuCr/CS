#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[101000],n,mx,i;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        if(i>1)
        {
            if(v[i]<mx-1)
            {
                cout<<"No";
                return 0;
            }
        }
        mx = max(mx,v[i]);
    }
    cout<<"Yes";

}
