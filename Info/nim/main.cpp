#include <cstdio>

using namespace std;

FILE *f=fopen("nim.in","r");
FILE *g=fopen("nim.out","w");

#define fs(n) fscanf(f,"%d",&n)
#define fp fprintf
int t,i,j,n,x,s;
int main()
{
    fs(t);
    for(i=1;i<=t;++i)
    {
        fs(n);
        s=0;
        for(j=0;j<n;++j)
        {
            fs(x);
            s^=x;
        }
        if(s)
            fp(g,"DA\n");
        else
            fp(g,"NU\n");
    }
}
