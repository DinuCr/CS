#include <cstdio>
#include <cstring>
using namespace std;
const int kc=12,nmax=1+kc*kc*kc*kc*kc;
int a[nmax];
char o[13],cmin[6],cmax[6],cu[6],s[6];
int nrcuv=0,l[30],vmin=nmax,vmax=-1,n,i,vc,p,j;

int  val(char *c)
{
    int s=0,p=1,i;
    for(i=4; i>=0; i--)
    {
        s+=p*l[c[i]-'a'];
        p*=kc;
    }
    return s;
}

char * cuv(int n)
{
    char i;
    s[5]=0;
    for(i=4; i>=0; i--)
    {
        s[i]=o[n%12];
        n/=12;
    }
    return s;
}
int main()
{
    FILE *fi=fopen("zimeria.in","r");
    FILE *fo=fopen("zimeria.out","w");
    fscanf(fi,"%d\n%d\n",&p,&n);
    fscanf(fi,"%s\n",o);
    for(i=0; i<12; i++)l[o[i]-'a']=i;
    for(i=1; i<=n; i++)
    {
        fscanf(fi,"%s\n",cu);
        vc=val(cu);
        if(vc>vmax)vmax=vc;
        if(vc<vmin)vmin=vc;
        if(a[vc]==0)nrcuv++;
        a[vc]++;
    }
    if(p==1)fprintf(fo,"%d",nrcuv);
    else
    {
        cu[5]=0;
        for(i=vmin; i<=vmax; i++)
            if(a[i]!=0)
            {
                strcpy(cu,cuv(i));
                for(j=1; j<=a[i]; j++)fprintf(fo,"%s\n",cu);
            }
    }
    fclose(fi);
    fclose(fo);
    return 0;
}
