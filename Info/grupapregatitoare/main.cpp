#include <iostream>
#include <cstdio>

using namespace std;

struct nod
{
    int s,p;
};
nod v[6100];
int n , p , i , ok = 0, poz , mx , mn = 100000 , j;

int main()
{
    freopen("grupapregatitoare.in","r",stdin);
    freopen("grupapregatitoare.out","w",stdout);

    scanf("%d%d",&n,&p);

    for(i=0; i<n; ++i)
    {
        scanf("%d%d",&v[i].p,&v[i].s);

        if(v[i].p<v[i].s)
            swap(v[i].s,v[i].p);

        if(!(v[i].p%p))
        {
            if(mx<v[i].p)
            {
                mx=v[i].p;
                poz=i;
                ok=1;
            }
        }
        else
        if(!ok)
        {
            if(!(v[i].s%p) && mn>v[i].p-v[i].s)
            {
                mn=v[i].p-v[i].s;
                poz=i;
            }
        }
    }
    int s = 0;
    for(i=0; i<poz; ++i)
        s+=v[i].p;

    if(ok)
        s+=v[i].p;
    else
        s+=v[i].s;

    for(i=poz+1; i<n; ++i)
        s+=v[i].p;
    printf("%d\n",s);

    for(i=0; i<n; ++i)
        if(v[i].p%2==1 && v[i].s%2==0)
            swap(v[i].p,v[i].s);

    for(i=n; i<(n<<1); ++i)
        v[i]=v[i-n];

    mx=0;
    for(i=1; i<n; ++i)
    {
        j=i;
        while(j<(n<<1)-1 && j-i<n-1 && v[j].p%2==v[j+1].p%2)
            ++j;
        mx=max(mx,j-i+1);
        j=i;
        while(j<(n<<1)-1 && j-i<n-1 && v[j].s%2==v[j+1].s%2)
            ++j;
        mx=max(mx,j-i+1);
    }
    printf("%d",mx);
}
