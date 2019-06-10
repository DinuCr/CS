#include <iostream>

using namespace std;
long long n,v[200100],mn,mx,p,p1,i,s;
int main()
{
    cin>>n;
    mn=10000000000;
    mx=0;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
        if(v[i]<=mn)
            mn=v[i],p=i;
    }
    for(i=1;i<=n;i++)
        if(v[i]==mn)
        break;
    mx=n-p+i-1;
    p1=i;
    for(i=p1+1;i<=p;i++)
        if(v[i]==mn)
    {
        if(i-p1>mx)
            mx=i-p1-1;
        p1=i;
    }
    s=mx+n*mn;
    cout<<s;
}
