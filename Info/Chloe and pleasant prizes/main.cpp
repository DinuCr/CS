#include <iostream>
#include <vector>

using namespace std;

#define nmax 200100
#define ll long long

vector <int> v[nmax];
ll d[nmax];
ll mx[nmax];
int viz[nmax];
ll ans;
int i,n;

void df(int x)
{
    mx[x]=-1e18;
    for(auto it:v[x])
    {
        if(viz[it])
            continue;
        viz[it]=1;
        df(it);
        mx[x]=max(mx[x],mx[it]);
        d[x]+=d[it];
    }
    mx[x]=max(mx[x],d[x]);
}

void query(int x)
{
    ll mx1 = -1e18;
    ll mx2 = -1e18;
    for(auto it:v[x])
    {
        if(!viz[it])
            continue;
        if(mx[it]>mx1)
        {
            mx2=mx1;
            mx1=mx[it];
        }
        else
        if(mx[it]>mx2)
        {
            mx2=mx[it];
        }
    }
    if(mx2 != -1e18)
        ans = max(ans,mx1+mx2);
    for(auto it:v[x])
    {
        if(!viz[it])
            continue;
        viz[it]=0;
        query(it);
    }
}

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>d[i];
    for(i=1; i<n; ++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    viz[1]=1;
    df(1);

    ans = -1e18;

    viz[1]=0;
    query(1);

    if(ans == -1e18)
        cout<<"Impossible";
    else
        cout<<ans;
}
