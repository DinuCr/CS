#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

pair<int,int> v[1010];
int n,i;

int cmp(pair<int,int> a,pair<int,int> b)
{
    return a.f>b.f;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);


    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i].f;
        v[i].s=i;
    }

    sort(v+1,v+n+1,cmp);

    ll cnt = 0;
    for(i=1; i<=n; ++i)
        cnt+=v[i].f*(i-1)+1;
    cout<<cnt<<'\n';
    for(i=1; i<=n; ++i)
        cout<<v[i].s<<' ';
}
