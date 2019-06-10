#include<iostream>
using namespace std;
int st,n,v[100],x[100],s[100];
bool conditii(int k)
{
    int i,s;
    s=0;
    for(i=1;i<=k;i++)
    s+=x[i]*v[i];
    if(s>st)
    return 0;
    if(k==n && s!=st)
    return 0;
    return 1;
}
void tipar()
{
    int i;
    for(i=1;i<=n;i++)
    if(x[i]!=0)
    cout<<x[i]<<' '<<v[i]<<'*';
    cout<<endl;
}
void bkt(int k)
{
    int l;
    if(k==n+1)
        tipar();
    else
    for(l=0;l<=s[k];l++)
    {
        x[k]=l;
        if(conditii(k))
        bkt(k+1);
    }
}
int main()
{
    int i;
    cin>>st>>n;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
        s[i]=st/v[i];
    }
    bkt(1);
    return 0;
}
