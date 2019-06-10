#include <iostream>

using namespace std;

int main()
{
    long long n,k;
    cin>>n>>k;
    if(k%2==1)
        cout<<1;
    else
    {
        long long ok=0;
        long long x=1;
        for(int i=1; i<=n; ++i)
            x*=2;
        --x;
        int ans=n;
        n=x;
        while(n && !ok)
        {
            if((n+1)/2==k)
            {
                ok=1;
                cout<<ans;
            }
            else
            {
                if(k>(n+1)/2)
                    k=2*(n+1)/2-k;
                n/=2;
                --ans;
            }
        }
    }
}
