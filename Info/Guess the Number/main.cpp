#include <iostream>
#include <cstdio>

using namespace std;

int s,d,mid;
char ss[3];

int main()
{
    s=1;
    d=1000000;
    while(s<d)
    {
        mid=(s+d+1)/2;
        printf("%d\n",mid);
        fflush(stdout);

        scanf("%s",&ss);
        if(ss[0]=='<')
            d=mid-1;
        else
            s=mid;
    }
    printf("! %d\n",s);
    fflush(stdout);
}
