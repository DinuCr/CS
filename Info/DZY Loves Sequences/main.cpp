#include <iostream>

using namespace std;

long long v[100110],j,i,mx,p,n;
long long w[100110],k;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    w[++k]=1;
    for(i=2; i<=n; ++i)
        if(v[i-1]>=v[i])
            w[++k]=i;
    w[++k]=n+1;
    for(i=1; i<k; ++i)
    {
        if((v[w[i]]==1 || w[i]==1) && w[i+1]==n+1)
        mx=max(mx,w[i+1]-w[i]);
        else
        mx=max(mx,w[i+1]-w[i]+1);

        if(v[w[i+1]+1]>v[w[i+1]-1]+1)
            mx=max(mx,w[i+2]-w[i]);
    }
    if(mx>n)
        mx=n;
    cout<<mx;
}
