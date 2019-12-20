#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair

const int nmax = 5010;

int a[nmax], b[nmax], c[nmax], def[nmax], last[nmax];
vector <int> v[nmax];
priority_queue < pair<int,int>, vector <pair<int,int> >, greater<pair<int,int> > > q;
int n,m,k;

int main()
{
    cin>>n>>m>>k;
    for(int i=1; i<=n; ++i)
    {
        cin>>a[i]>>b[i]>>c[i];
        last[i]=i;
    }
    for(int i=1; i<=m; ++i)
    {
        int a,b;
        cin>>a>>b;
        last[b]=max(last[b],a);
    }
    for(int i=1; i<=n; ++i)
        v[last[i]].pb(i);
    for(int i=1; i<=n; ++i)
    {
        if(k>=a[i])
            k+=b[i];
        else
        {
            if(q.size()+k<a[i])
            {
                cout<<-1;
                return 0;
            }
            else
            {
                while(k<a[i])
                {
                    int y = q.top().s;
                    k++;
                    def[y]=0;
                    q.pop();
                }
                k+=b[i];
            }
        }
        for(auto it:v[i])
            if(def[it]==0)
            {
                def[it]=1;
                k--;
                q.push(mp(c[it],it));
            }
    }
    while(k<0)
        ++k,q.pop();
    int ans = 0;
    while(q.size())
    {
        ans+=q.top().f;
        q.pop();
    }
    cout<<ans;
}
