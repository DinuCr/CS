#include <iostream>
#include <cstdio>
using namespace std;
long long v[500010],sp,d[500010],i,mx,n;
char s[500010];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    scanf("%s",&s);
    for(i=0;i<n;i++)
    {
        if(s[i]=='A')
            d[i+1]=d[i]-v[i+1];
        else
        {
            d[i+1]=d[i]+v[i+1];
            sp+=v[i+1];
        }
    }
    for(i=1;i<=n;i++)
        mx=max(mx,d[i]*(-1));
    for(i=n;i>1;i--)
        mx=max(mx,(d[n]-d[i])*(-1));
    cout<<sp+mx;
}
