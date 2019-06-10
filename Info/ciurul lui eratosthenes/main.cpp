#include <cstdio>
#include <bitset>

using namespace std;

#define fs fscanf
#define fp fprintf
#define nmax 2000000/2+1

bitset <nmax> v;
int n,nr,i,j;

int main()
{
    FILE *f=fopen("ciur.in","r");
    fs(f,"%d",&n);
    nr=1;
    fclose(f);
    for(i=1; (((i*i)<<1)+(i<<1))<=n; ++i)
    {
        if(!v[i])
        {
            for(j=(((i*i)<<1)+(i<<1)) ; (j<<1)+1 <=n; j+= (i<<1) +1 )
                v[j]=1;
        }
    }
    for(i=1; (i<<1) +1 <=n; ++i)
        if(!v[i])
        nr++;
    FILE *g=fopen("ciur.out","w");
    fp(g,"%d",nr);
    fclose(g);
    return 0;
}
