#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int n,k,i;
int v[200010][20];

int find_ans(int p)
{
    int ans = 0;
    int curr = 0;

    for(int i=0; i<20; ++i)
    {
        if(curr<k)
            ans+=min(k-curr,v[p][i])*i,curr+=min(k-curr,v[p][i]);
        if(curr==k)
            return ans;
    }
    return 1e9;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n>>k;

    int ans = 1e9;

    for(i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        v[x][0]++;
    }

    for(i=200000; i>=0; --i)
    {
        int p = 1;
        int j = i/2;
        while(j)
        {
            v[j][p]+=v[i][0];
            p++;
            j/=2;
        }
        ans=min(ans,find_ans(i));
    }

    cout<<ans;
}
