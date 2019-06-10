#include<iostream>
using namespace std;
int n,x,v[150001],mn,s,k,i;
int main()
{
    cin>>n>>k;
    for(i=1;i<=k;i++)
    {
        cin>>v[i];
        s+=v[i];
    }
    mn=s;x=1;
    for(i=k+1;i<=n;i++)
    {
        cin>>v[i];
        s-=v[i-k];
        s+=v[i];
        if(s<mn)
        {
            mn=s;
            x=i-k+1;
        }
    }
    cout<<x;
    return 0;
}
