#include <iostream>

using namespace std;

int n,i,d[100100],j,ans;

int main()
{
    cin>>n;
    for(i=2; i<=n+1; ++i)
        if(!d[i])
        {
            d[i]=1;
            ans=max(ans,1);
            for(j=i*2; j<=n+1; j+=i)
            if(!d[j])
            {
                d[j]=2;
                ans=max(ans,d[j]);
            }
        }
    cout<<ans<<'\n';
    for(i=2; i<=n+1; ++i)
        cout<<d[i]<<' ';
}
