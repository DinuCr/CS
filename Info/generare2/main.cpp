#include <iostream>
using namespace std;
int v[10000],w[10000],k,i,n,a,x,y;
inline void ad(int v[],int &n,int x)
{
    v[++n]=x;
}
inline void s(int v[],int &n,int &x)
{
    x=v[n--];
}
int main()
{
    cin>>n>>a>>x>>y;
    ad(v,k,a);w[a]=1;
    while(k>0)
    {
        s(v,k,a);
        if(a+x<=n && !w[a+x])
        {
            ad(v,k,a+x);
            w[v[k]]=1;
        }
        if(a+y<=n && !w[a+y])
        {
            ad(v,k,a+y);
            w[v[k]]=1;
        }
    }
    for(i=0;i<=n;i++)
    if(w[i])
    cout<<i<<' ';
}
