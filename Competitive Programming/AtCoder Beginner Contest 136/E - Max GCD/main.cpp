#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int n,k,sum;
int w[100100];
pair<int,int> v[100100];

int compute(int x)
{
    int i;
    for(i=1; i<=n; ++i)
        v[i].s=w[i],
        v[i].f=v[i].s - (v[i].s/x*x);
    sort(v+1,v+n+1);
    i = 1;
    int j = n;
    int cnt = 0;
    while(i<j)
    {
        int p = min(v[i].s- v[i].s/x*x, (v[j].s/x+1)*x-v[j].s);
        cnt+=p;
        if(cnt>k)
            return 0;
        v[i].s-=p;
        v[j].s+=p;
        if(v[i].s%x==0)
            ++i;
        if(v[j].s%x==0)
            --j;
    }
    return 1;
}


int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n>>k;
    int i;
    for(i=1; i<=n; ++i)
    {
        cin>>w[i];
        sum+=w[i];
    }

    int ans = 0;

    int lim = sqrt(sum);

    for(i=1; i<=lim; i++)
        if(sum%i==0)
        {
            if(compute(i))
                ans=max(ans,i);
            if(compute(sum/i))
                ans=max(ans,sum/i);
        }
    cout<<ans;
}
