#include <iostream>

using namespace std;

long long n,m,x,y,curr,ans;

int main()
{
    cin>>n>>m>>x>>y;
    for(curr=1; curr<=n; curr<<=1);
    for( ; curr; curr>>=1)
        if(ans+curr<=n)
        {
            if(m-(ans+curr)*x+(n-ans-curr)*y>=0)
                ans+=curr;
        }
    cout<<ans;
}
