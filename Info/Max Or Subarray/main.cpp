#include <iostream>

using namespace std;

#define nmax (int)1e5+10

int n,curr,i,ans;
int v[nmax],mx[nmax];
int last[nmax][31];

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        mx[i]=v[i]|mx[i-1];
        for(int j=0; j<=30; ++j)
            if((1<<j)&v[i])
                last[i][j]=i;
            else
                last[i][j]=last[i-1][j];
    }
    if(mx[n]==0)
    {
        cout<<1;
        return 0;
    }
    ans = 1e9;
    for(i=1; i<=n; ++i)
    {
        if(mx[i]!=mx[n])
            continue;
        int curr = 1e9;
        for(int j=0; j<=30; ++j)
            if(last[i][j]!=0)
                curr=min(curr,last[i][j]);
        ans=min(ans,i-curr+1);
    }
    cout<<ans;
}
