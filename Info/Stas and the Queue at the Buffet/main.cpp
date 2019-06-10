#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

pair<int,int> v[(int)2e5];
int a[(int)2e5];
int b[(int)2e5];
int ans[(int)2e5];
int n;

int cmp(pair<int,int> i, pair<int,int> j)
{
    if(i.s!=j.s)
        return i.s>j.s;
    int x = a[i.f];
    int y = b[i.f];
    int z = a[j.f];
    int t = b[j.f];
    return (min(x,y)>min(z,t));
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int i,j;
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>a[i]>>b[i];
    }
    for(i=1; i<=n; ++i)
    {
        v[i].f=i;
        v[i].s=abs(a[i]-b[i]);
    }
    sort(v+1,v+n+1,cmp);
    i=1,j=n;
    for(int k=1; k<=n; ++k)
    {
        int x = v[k].f;
        if(a[x]>b[x])
            ans[i++]=x;
        else
            ans[j--]=x;
    }
    ll cnt = 0;
    for(i=1; i<=n; ++i)
    {
        cnt+=(1LL*a[ans[i]]*(i-1)+1LL*b[ans[i]]*(n-i));
    }
    cout<<cnt;
}
