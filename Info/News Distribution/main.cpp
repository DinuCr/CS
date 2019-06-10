#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int t[500010];
int cnt[500010];
int n,m,i,x,a,b;

int root(int x)
{
    if(!t[x])
        return x;
    t[x]=root(t[x]);
    return t[x];
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n>>m;
    while(m--)
    {
        cin>>x;
        if(x)
            cin>>a;
        for(i=2; i<=x; ++i)
        {
            cin>>b;
            if(root(a)!=root(b))
                t[root(a)]=root(b);
        }
    }
    for(i=1; i<=n; ++i)
        cnt[root(i)]++;
    for(i=1; i<=n; ++i)
        cout<<cnt[root(i)]<<' ';

}
