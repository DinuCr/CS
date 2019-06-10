#include <iostream>

using namespace std;

int n,v[100010],i,j,mx,d[10010],MX;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
    }
    for(i=1; i<=n; ++i)
    {
        mx=0;
        for(j=1; j<i; ++j)
        {
            if(v[i]>v[j] && gcd(v[i],v[j])>1)
                mx=max(mx,d[j]);
        }
        d[i]=mx+1;
        MX=max(MX,d[i]);
    }
    cout<<MX;
}
