#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

char v[1000];
int n,t,i;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1; i<=n; ++i)
            cin>>v[i];
        int curr = 0;
        for(i=1; i<=n; ++i)
            if(v[i]=='8')
            {
                curr=i;
                break;
            }
        if(curr==0)
            cout<<"NO\n";
        else
        if(n-curr+1>=11)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
