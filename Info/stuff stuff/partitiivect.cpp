#include<iostream>
using namespace std;
int n,v[100],x[100],i;
int cond(int k)
{
    int mx,i;
    mx=0;
    for(i=1;i<k;i++)
        mx=max(x[i],mx);
    if(x[k]-1>mx)
    return 0;
    return 1;
}
void tipar()
{
    int i,j,mx;
    mx=0;
    for(i=1;i<=n;i++)
    mx=max(x[i],mx);
    for(i=1;i<=mx;i++)
    {
        cout<<'{';
        for(j=1;j<=n;j++)
        if(x[j]==i)
        cout<<j<<',';
        cout<<'}';
    }
    cout<<endl;
}
void bkt(int k)
{
    int l;
    if(k==n+1)
    tipar();
    else
    for(l=1;l<=k;l++)
    {
        x[k]=l;
        if(cond(k))bkt(k+1);
    }
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>v[i];
    bkt(1);
    return 0;
}
