#include <iostream>
using namespace std;
int s1[400010],s0[400000],v[400010],i,j,n,k,mx,ld,ls;
int main()
{
    cin>>n>>k;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        s1[i]+=v[i]+s1[i-1];
        s0[i]+=(!v[i])+s0[i-1];
    }
    j=0;
    for(i=1; i<=n; ++i)
    {
        if(s0[i]-s0[j]<=k)
            {
                if(s1[i]-s1[j]+s0[i]-s0[j]>mx)
                {
                    ls=j+1;
                    ld=i;
                    mx=s1[i]-s1[j]+s0[i]-s0[j];
                }
            }
        else
            while(s0[i]-s0[j]>  k && j<i)
            ++j;
    }
    cout<<mx<<'\n';
    for(i=1; i<ls; ++i)
        cout<<v[i]<<' ';
    if(ls + ld >0)
    for(i=ls; i<=ld ; ++i)
        cout<<"1 ";
    for(i=ld+1; i<=n; ++i)
        cout<<v[i]<<' ';
}
