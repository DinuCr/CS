#include <iostream>

using namespace std;

#define nmax 100100

long long v[nmax];
long long r[nmax];
long long sum[nmax];
long long ord[nmax];
long long viz[nmax];
long long w[nmax];
long long k;
long long n,i,j,mx,x;

long long root(long long x)
{
    if(r[x]==0)
        return x;
    r[x]=root(r[x]);
    return r[x];
}

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    for(i=1; i<=n; ++i)
        cin>>ord[i];
    mx=0;
    for(i=n; i>0; --i)
    {
        w[++k]=mx;
        x=ord[i];
        viz[x]=1;
        long long s1=sum[root(x-1)];
        long long s2=sum[root(x+1)];
        if(viz[x-1])
            r[root(x)]=root(x-1);
        if(viz[x+1])
            r[root(x+1)]=root(x);
        sum[root(x)]=s1+s2+v[x];
        mx=max(mx,sum[root(x)]);
    }
    for(i=k; i>0; --i)
        cout<<w[i]<<'\n';
}
