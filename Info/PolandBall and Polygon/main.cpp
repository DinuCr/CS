#include <iostream>

using namespace std;

#define zeros(x) ((x^(x-1))&x)

int n,v[1000100],i,b,k;

void add(int ls,int x)
{
    for(;ls<=n;ls+=zeros(ls))
        v[ls]+=x;
}

int compute(int x)
{
    int s=0;
    for(;x>0;x-=zeros(x))
        s+=v[x];
    return s;
}

int main()
{
    cin>>n>>k;
    long long ans = 1;
    int a = 1;
    if(k>n/2)
        k=n-k;
    for(i=1; i<=n; ++i)
    {
        long long curr = 1;
        b = a + k;
        if(b>n)
            b%=n;
        if(b>a)
            curr += compute(b-1)-compute(a);
        else
            curr += compute(b-1) - compute(a) + compute(n);
        ans+=curr;
        add(a,1);
        add(b,1);
        a=b;
        cout<<ans<<' ';
    }
}
