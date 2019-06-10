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
    ll t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ll cnt = 0;
        while(n!=0)
        {
            if(n%k==0)
                cnt++,n/=k;
            else
            {

            cnt+=n%k;
            n = n - n%k ;
            }
        }
        cout<<cnt<<'\n';
    }
}
