#include <iostream>
#include <cstdio>
using namespace std;
int mx,h[300100];
void update(int r,int s,int d,int a,int b,int x)
{
    if(s!=d)
    {
        if(a<=d && s<=b)
        {
            int m=(s+d)/2;
            if(a<=m)
                update(r*2,s,m,a,b,x);
            if(b>m)
                update(r*2+1,m+1,d,a,b,x);
            h[r]=max(h[r*2],h[2*r+1]);
        }
    }
    else
    h[r]=x;
}
void compute(int r,int s,int d,int a,int b)
{
    if(a<=d && b>=s)
    {
        if(s>=a && d<=b)
            mx=max(mx,h[r]);
        else
        {
            int m=(s+d)/2;
            if(a<=m)
                compute(r*2,s,m,a,b);
            if(b>m)
                compute(r*2+1,m+1,d,a,b);
        }
    }
}
int main()
{
    int n,i,x,p,m,a,b;
    freopen("arbint.in","r",stdin);
    freopen("arbint.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; ++i)
    {
        scanf("%d",&x);
        update(1,1,n,i,i,x);
    }
    for(i=0; i<m; ++i)
    {
        scanf("%d",&p);
        switch(p)
        {
        case 0:
            scanf("%d%d",&a,&b);
            mx=0;
            compute(1,1,n,a,b);
            printf("%d\n",mx);
            break;
        case 1:
            scanf("%d%d",&a,&b);
            update(1,1,n,a,a,b);
            break;
        }
    }
}
