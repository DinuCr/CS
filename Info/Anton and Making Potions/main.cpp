#include <iostream>
#include <algorithm>

using namespace std;

int pot[1001000][3];
int nr[1001000];
int cost[1001000];
int n,m,k,i,j,x,s;

int main()
{
    cin>>n>>m>>k;
    cin>>x>>s;
    for(i=1; i<=m; ++i)
        cin>>pot[i][0];
    //sec
    for(i=1; i<=m; ++i)
        cin>>pot[i][1];
    //cost1

    for(i=1; i<=k; ++i)
        cin>>nr[i];
    //nr
    for(i=1; i<=k; ++i)
        cin>>cost[i];
    //cost
    long long ans=1LL*x*n;
    pot[0][0]=x;
    for(i=0; i<=m; ++i)
    {
        int j=0;
        if(cost[1]<=s-pot[i][1])
            j = upper_bound(cost+1,cost+k+1,s-pot[i][1])-cost-1;
        if(j>k)
            j=k;
        if(s>=pot[i][1])
            ans=min(ans,(max(n-nr[j],0))*1LL*pot[i][0]);
    }
    cout<<ans;
}
