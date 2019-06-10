#include <iostream>

using namespace std;

unsigned long long i,n,ans,w[110],v[110],s,d[110],k;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

unsigned long long ciclu(unsigned long long x)
{
    d[x]=k++;
    if(!d[v[x]])
        ciclu(v[x]);
    else
        w[x]=1;
}

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        w[v[i]]=1;
    }
    for(i=1; i<=n; ++i)
    {
        if(w[i]==0)
        {
            cout<<-1;
            return 0;
        }
        w[i]=0;
    }
    for(i=1; i<=n; ++i)
        if(d[i]==0)
        {
            k=1;
            ciclu(v[i]);
        }
    ans = 1;
    for(i=1; i<=n; ++i)
        if(w[i] && d[i]!=2)
        {
            if(d[i]%2==0)
                d[i]/=2;
            ans=ans*d[i]/gcd(ans,d[i]);
        }
    cout<<ans;
}
