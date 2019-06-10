#include <iostream>
#include <cstdio>
using namespace std;

int v[100],i,ok,nr,n,d,j;
char s[10];

int main()
{
    for(i=2; i<=100; ++i)
    {
        ok=1;
        for(d=2; d<=i/2; ++d)
            if(i%d==0)
            ok=0;
        if(ok)
        {
            ++n;
            v[n]=i;
        }
    }
    for(i=1; v[i]<=50 && nr<2; ++i)
    {
        printf("%d\n",v[i]);
        fflush(stdout);

        scanf("%s",&s);
        if(s[0]=='y')
        {
            ++nr;
            for(j=i; v[j]*v[i]<=100 && nr<2; ++j)
            {
                printf("%d\n",v[i]*v[j]);
                fflush(stdout);

                scanf("%s",&s);
                if(s[0]=='y')
                    nr++;
            }
            if(v[i]*v[j]>100)
                break;
        }
    }
    if(nr<2)
        printf("prime\n");
    else
        printf("composite\n");
    fflush(stdout);
}
