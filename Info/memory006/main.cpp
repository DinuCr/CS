#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("memory006.in");
ofstream fout("memory006.out");

#define ll long long
#define f first
#define s second
#define mp make_pair

queue <pair<short,short> > q;
ll x,ok;
ll i,n,k,ans;

inline ll cnt(ll x)
{
    ll ans = 0 ;
    while ((x&1LL)==0)
    {
        x>>=1;
        ++ans;
    }
    if(x!=1)
        return 0;
    return ans;
}

int main()
{
    fin>>n>>k;
    ll curr = 0;
    ok=1;
    for(i=1; i<=n; ++i)
    {
        fin>>x;
        ll a = cnt(x);
        if(x==1)
            ok++;
        else
        {
            if(a==0)
            {
                curr=0;
                while(!q.empty())
                    q.pop();
                ok=1;
            }
            else
            {
                q.push(mp(a,ok));
                curr+=a;
                ok=1;
            }
        }
        if(curr==k)
            ans+=q.front().s;
        while(curr>k && !q.empty())
        {
            curr-=q.front().f;
            q.pop();
            if(curr==k && !q.empty())
            {
                ans+=q.front().s;
                curr-=q.front().f;
                q.pop();
            }

        }
    }
    fout<<ans;
}
