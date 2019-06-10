#include <cstdio>
#include <iostream>
using namespace std;
int n,k,i,j,v[300],r[300],d[300],mx;

int main()
{
    freopen("cuvinte.in","r",stdin);
    freopen("cuvinte.out","w",stdout);

    scanf("%d%d",&n,&k);

    for(i=1; i<=n; ++i)
        scanf("%d",&v[i]);

    for(i=n; i; --i)
    {
        for(j=i+1; j<=n ; ++j)
            if(v[j]>=v[i])
            {
                if(d[j]>=d[i])
                {
                    d[i]=d[j]+1;
                    r[i]=r[j];
                }
                else
                if(d[j]+1==d[i])
                    r[i]+=r[j];
            }

        if(d[i]==0)
        {
            d[i]=1;
            r[i]=1;
        }
        mx=max(mx,d[i]);
    }
    for(i=1; mx && k; ++i)
    {
        if(d[i]==mx)
        {
            if(r[i]<k)
                k-=r[i];
            else
            {
                cout<<i<<' ';
                mx--;
            }
        }
    }
}
