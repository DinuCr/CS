#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
//FILE *f=fopen("boo.in","r");
//FILE *g=fopen("boo.out","w");
int t,i,j,n,k,m,d,ok,s,p;
struct coord
{
    int x,y;
};
coord v[10000000];
coord w[20000];
int main()
{
    scanf("%d",&t);
    for(p=0; p<t; ++p)
    {
        s=0;
        scanf("%d",&n);
        for(i=1; i<=n; ++i)
            scanf("%d%d",&w[i].x,&w[i].y);
        for(k=1; k<=n; ++k)
        {
            m=0;
            for(i=k+1; i<=n; ++i)
            {
                d=abs(pow((w[i].x-w[k].x),2))+abs(pow((w[i].y-w[k].y),2));
                ok=0;
                for(j=1; j<=m; j++)
                    if(v[j].x==d)
                    {
                        v[j].y++;
                        ok=1;
                        break;
                    }
                if(!ok)
                {
                    ++m;
                    v[m].x=d;
                    v[m].y=1;
                }
            }
            for(i=1; i<k; ++i)
            {
                d=abs(pow((w[i].x-w[k].x),2))+abs(pow((w[i].y-w[k].y),2));
                ok=0;
                for(j=1; j<=m; j++)
                    if(v[j].x==d)
                    {
                        v[j].y++;
                        ok=1;
                        break;
                    }
                if(!ok)
                {
                    ++m;
                    v[m].x=d;
                    v[m].y=1;
                }
            }
            for(i=1; i<=m; i++)
                s+=v[i].y*(v[i].y-1)/2;
        }
        printf("Case #%d: %d\n",p+1,s);
    }
}
