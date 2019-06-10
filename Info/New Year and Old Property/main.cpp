#include <iostream>

using namespace std;
long long v[63],w[4000],k,i,j,a,b,n,p1,p2;
long long cb(long long a)
{
    int ls=0,m;
    int ld=k;
    while(ls<=ld)
    {
        m=(ls+ld)/2;
        if(w[m]==a)
        return m;
        else
        if(w[m]>a)
            ld=m-1;
        else
            ls=m+1;
    }
    return ld;
}
int main()
{
    cin>>a>>b;
    v[0]=1;
    v[1]=2;
    k=-1;
    for(i=2;i<=62;i++)
        v[i]=v[i-1]*2;
    for(i=1;i<=62;i++)
    {
        n=v[i]-1;
        for(j=i-2;j>=0;j--)
            w[++k]=n-v[j];
    }
    p1=cb(a);
    p2=cb(b);
    if(w[p1]==a)
        p1--;
    cout<<p2-p1;
}
