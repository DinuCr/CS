#include<iostream>
#include<stdio.h>
using namespace std;
FILE *f=fopen("livada1.in","r");
FILE *g=fopen("livada1.out","w");
long long cnt,v[700001],i,n,m,p,nr,j,mx,x,nrap,z;
int main()
{
    fscanf(f,"%lld%lld%lld",&n,&m,&p);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%lld",&v[1]);
        nr=1;
        for(j=2;j<=m;j++)
        {
            fscanf(f,"%lld",&v[j]);
            if(v[j]==v[j-1])
                nr++;
            else
                nr=1;
            mx=max(mx,nr);
        }
        cnt=0;
                    x=-1;
                    for (j=1;j<=m;j++)
                            if (cnt==0)
                                {
                                  cnt++;
                                   x=v[j];
                                }
                            else
                             if (x==v[j])
                                  cnt++;
                            else
                                  cnt--;
              nrap=0;
              for (j=1;j<=m;j++)
                      if (x==v[j])
                             nrap++;
              if (nrap>m/2)
                z++;

    }
    fprintf(g,"%lld\n%lld",z,mx);
    return 0;
}
