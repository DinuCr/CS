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

    int x;

    cin>>x;
    int pr = 1;
    int ans = 1;
    int cnt = 0;
    int x2 = x;
    while(x)
    {
        pr*=x%10;
        x/=10;
        cnt++;
    }
    ans=max(pr,(int)pow(9,cnt-1));
    vector <int> v;
    x=x2;
    while(x)
    {
        v.pb(x%10);
        x/=10;
    }
    reverse(v.begin(),v.end());
    for(int i=0; i<v.size(); ++i)
    {
        int curr = 1;
        for(int j=0; j<i; ++j)
            curr*=v[j];
        curr*=v[i]-1;
        curr*=pow(9,v.size()-i-1);
        ans=max(ans,curr);
    }
    cout<<ans;
}
