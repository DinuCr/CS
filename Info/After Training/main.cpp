#include <iostream>

using namespace std;

int n,m,v[10000],i;

int main()
{
    cin>>m>>n;
    if(n%2==0)
        while(m)
        {
            for(i=0; i<n/2 && m; ++i)
            {
                cout<<n/2-i<<'\n';
                --m;
                if(m)
                {
                    cout<<n/2+i+1<<'\n';
                    --m;
                }
            }
        }
    else
    {
        while(m)
        {
            cout<<(n+1)/2<<'\n';
            --m;
            for(i=1; i<=n/2 && m; ++i)
            {
                cout<<(n+1)/2-i<<'\n';
                --m;
                if(m)
                {
                    cout<<(n+1)/2+i<<'\n';
                    --m;
                }
            }
        }
    }
}
