#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("elmaj.in","r",stdin);
    freopen("elmaj.out","w",stdout);

    int n,x=0,nr=1;

    scanf("%d",&n);

    int v[n],i;

    for(i=0; i<n; ++i)
    {
        scanf("%d",&v[i]);
        if(v[i]==x)
            ++nr;
        else
        {
            --nr;
            if(!nr)
            {
                x=v[i];
                nr=1;
            }
        }
    }
    nr=0;
    for(i=0; i<n; ++i)
        if(v[i]==x)
            ++nr;

    if(nr>n/2)
    {
        printf("%d %d",x,nr);
    }
    else
        printf("-1");
}
