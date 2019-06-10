#include<iostream>
using namespace std;
int n,i,w[100],m[100],v[100],x[100],mt,mx;
int cond(int k)
{
    int i,s;
    s=0;
    for(i=1;i<=k;i++)
    s+=x[i]*m[i];
    if(s>mt)
    return 0;
    return 1;
}
void tipar()
{
    int i,s=0;
    for(i=1;i<=n;i++)
    s+=m[i]*x[i]*v[i];
    if(s>mx)
    {
        mx=s;
        for(i=1;i<=n;i++)
        w[i]=x[i];
    }
}
void bkt(int k)
{
    int l;
    if(k==n+1)
    tipar();
    else
    for(l=0;l<=1;l++)
    {
        x[k]=l;
        if(cond(k))bkt(k+1);
    }
}
int main()
{
    cin>>n;
    mx=0;
    for(i=1;i<=n;i++)
    cin>>m[i]>>v[i];
    cin>>mt;
    bkt(1);
    for(i=1;i<=n;i++)
    if(w[i]==1)
    cout<<m[i]<<' ';
    return 0;
}
