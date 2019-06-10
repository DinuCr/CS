#include <iostream>

using namespace std;
int v[1010],r[1010],a,i,n,k,mn,ok;

int main()
{
    cin>>n>>k;
    for(i=1; i<=n; ++i)
        cin>>r[i];
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        mn=min(mn,v[i]/r[i]);
    }
    a=mn;
    for(i=1; i<=n; ++i)
        v[i]-=mn*r[i];
    while(k>=0)
    {
        ok=1;
        for(i=1; i<=n; ++i)
        if(v[i]>=r[i])
            v[i]-=r[i];
        else
        {
            k-=r[i]-v[i];
            v[i]=0;
            if(k<0)
            {
                ok=0;
                break;
            }
        }
        if(ok)
            ++a;
    }
    cout<<a;
}
