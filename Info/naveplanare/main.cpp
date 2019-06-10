#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

FILE *f=fopen("naveplanare.in","r");
FILE *g=fopen("naveplanare.out","w");


int n,k,i,a,b,w[2000],q[2000],v1[201],v2[201],l=0,c=0,j;
int c1,c2,cl,cc;

int modul(int a)
{
   if(a<0)return a*-1; else return a;

}


int main()
{
    fscanf(f,"%d%d",&n,&k);
    for(i=1;i<=n;i++)
    {
          fscanf(f,"%d%d",&a,&b);
          a+=1000;
          b+=1000;
          if(!w[a]){w[a]=1;l++;}
          else v1[++v1[0]]=a;
          if(!q[b]){q[b]=1;c++;}
          else v2[++v2[0]]=b;
    }
    for(i=1;i<=2000;i++)
    {
        for(j=1;j<=v1[0];j++)
        if(modul(i-v1[j])+1<w[i] || w[i]==0)
                w[i]=modul(i-v1[j])+1;
        for(j=1;j<=v2[0];j++)
        if(modul(i-v2[j])+1<q[i] || q[i]==0)
                q[i]=modul(i-v2[j])+1;
    }
    sort(w+1,w+2001);
    sort(q+1,q+2001);
    c1=1;
    c2=1;
    cl=l;cc=c;
    while(w[c1]==0 && c1<2000)c1++;
    while(q[c2]==0 && c2<2000)c2++;
    while(cl<k) cl+=w[++c1]-1;
    while(cc<k) cc+=q[++c2]-1;
    cc-=c;
    cl-=l;
    fprintf(g,"%d",cc+cl);
    fclose(g);
    return 0;
}
