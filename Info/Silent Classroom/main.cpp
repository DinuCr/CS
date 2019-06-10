#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int ans, v[100];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int i,n;

    cin>>n;
    for(i=1; i<=n; ++i)
    {
        string s;
        cin>>s;
        v[s[0]-'a']++;
    }
    for(i=0; i<=26; ++i)
    if(v[i]>2)
    {
        int a = v[i]/2;
        int b = v[i]-a;
        ans+=(a-1)*a/2 + b*(b-1)/2;
    }
    cout<<ans;
}
