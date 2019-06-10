#include<iostream>
#include<fstream>
using namespace std;
int n,m,i,j,i0,j0,v[10010],x,k,s,r;
char c;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
    cin>>v[i];
    cin>>x;
    for(k=1;k<=x;k++)
    {
    cin>>c;
    if(c=='s')
    {
    s=0;
    cin>>i0>>j0>>r;
    for(i=i0;i<=j0;i++)
    if(v[i]%m==r)
    s+=v[i];
    cout<<s<<'\n';
    }
    else
    if(c=='-')
    {cin>>i0>>j0;v[i0]-=j0;if(v[i0]<0)v[i0]+=j0;;cout<<v[i0]<<'\n';}
    else
    {cin>>i0>>j0;v[i0]+=j0;cout<<v[i0]<<'\n';}
    }
}
