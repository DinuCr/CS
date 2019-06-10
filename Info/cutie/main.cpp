#include <iostream>
#include <fstream>
using namespace std;
typedef struct bi
{
    int a,ls,ld;
};
bi v[10010],b[10010];
int T,i,j,nri,nrs,n,m,k,x,q;
ifstream f("cutie.in");
ofstream g("cutie.out");
int main()
{
    f>>T;
    for(int zx=1;zx<=T;zx++)
    {
        f>>n>>k>>m;
        for(i=1;i<=n;i++)
        v[i].a=0;
        int a=1;
        for(i=1;i<=k;i++)
        {
            f>>x;
            for(j=a+1;j<x;j++)
            {
                v[j].ls=a;
                v[j].ld=x;
            }
            a=x;
        }
        for(i=a+1;i<n;i++)
        {
            v[i].ls=a;
            v[i].ld=n;
        }
        for(i=1;i<=m;i++)
        {
            f>>x;
            v[x].a++;
        }
        q=0;
        for(i=1;i<=n;i++)
        if(v[i].a)
        {
            b[++q].a=v[i].a;
            b[q].ls=i-v[i].ls;
            b[q].ld=v[i].ld-i;
        }


        nrs=nri=0;
        for(i=1;i<=q;i++)
        if(b[i].a>0)
        {
            if(b[i].ls%2==1 && b[i].ld%2==1)
            nrs+=b[i].a;
            else
            if(b[i].ls%2==1 xor b[i].ld%2==1)
            nri+=b[i].a;
        }
        if(nri==0)
        {
            if(nrs==0 || nrs%2==0)
            g<<'0';
            else
            g<<'1';
        }
        else
        {
            if(nri%2==1)
            g<<'1';
            else
            {
                if(nrs%2==1)
                    g<<'1';
                else
                    g<<'0';
            }
        }
    }
}
