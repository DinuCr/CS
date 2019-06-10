#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[1100];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n,i,h,ans;

    cin>>n>>h;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
    }
    i=1;
    ans = 1;
    for(i=1; i<=n; i<<=1);

    for( ; i; i>>=1)
    if(i+ans<=n)
    {
        vector <int> w;
        int curr = i+ans;
        for(int j=1; j<=curr; ++j)
            w.pb(v[j]);
        int h2 = h;
        sort(w.begin(),w.end());
        for(int j=w.size()-1; j>=0 && h2>=0; j-=2)
        {
            h2-=w[j];
        }
        if(h2>=0)
            ans+=i;
    }
    cout<<ans;
}
