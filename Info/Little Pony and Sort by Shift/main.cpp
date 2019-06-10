#include <iostream>

using namespace std;

int v[100100],n,i,ok,p,mn,mx,nr;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        if(i==1)
        {
            mn=mx=v[i];
        }
        mx=max(mx,v[i]);
        mn=min(mn,v[i]);
    }
    v[n+1]=v[1];
    for(i=2; i<=n+1; ++i)
    {
        if(v[i]<v[i-1])
        {
            nr++;
            p=i;
        }
    }
    if(nr>1)
        cout<<-1;
    else
    {
        if(p==0)
            cout<<0;
        else
            cout<<n-p+1;
    }
}
