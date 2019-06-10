#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

FILE *f=fopen("geometrie.in","r");
FILE *g=fopen("geometrie.out","w");


int n,m,i,a,b,j,k;

struct vec
{
    int x,y;
}v[100005],w[100005],c[100005];


double tr(vec a, vec b, vec c)
{
    double arie = b.x*c.y + a.x*b.y + a.y*c.x - b.x*a.y -c.x*b.y-c.y*a.x;
    arie = arie / 2.0;
    if(arie<0)arie = arie *-1.0;
    return arie;


}


bool cmp(vec a, vec b)
{
 if(a.x<b.x)return 1; else return 0;
}
bool cmp2(vec a, vec b)
{
    double tg1=0,tg2=0;
    if(a.x)tg1=a.y*1.0/a.x*1.0;
    if(b.x) tg2=b.y*1.0/b.x*1.0;
    if(tg1>tg2)return 1; else return 0;
}

int dreapta(vec a, vec b, vec c)
{
   int arie = b.x*c.y + a.x*b.y + a.y*c.x - b.x*a.y -c.x*b.y-c.y*a.x;
   arie = arie / 2.0;
   if(arie<0)return -1; else return 1;
  /* int A,B,C;
   A=b.x-a.x;
   B=a.y-b.y;
   C=(a.x-b.x)*(b.y-a.y);
   if(A*c.x+B*c.y+C>0)return 1; else return -1;*/
}



void solve()
{
  int i,nr;
  double sum=0;
  sort(w+1,w+k+1,cmp2);
  c[1]=w[1];
  c[2]=w[2];
  nr=2;
  for(i=3;i<=k;i++)
  {
     if(dreapta(c[nr],c[nr-1],w[i])>0)
     {
       nr++;
       c[nr].x=w[i].x;
       c[nr].y=w[i].y;
     }else
     {
     c[nr].x=w[i].x;
     c[nr].y=w[i].y;
     }
  }
  if(nr<3)fprintf(g,"%s\n","0.0");
  else
  {
  for(i=2;i<=nr-1;i++)
     sum+=tr(c[1],c[i],c[i+1]);
  fprintf(g,"%.1llf\n",sum);
  }



}


int main()
{
    fscanf(f,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
      fscanf(f,"%d%d",&v[i].x,&v[i].y);
    sort(v+1,v+n+1,cmp);
    for(i=1;i<=m;i++)
    {
       fscanf(f,"%d%d",&a,&b);
       j=1;
       while(v[j].x<=a && v[j].x)
       {
         w[j].x=v[j].x;
         w[j].y=v[j].y;
         j++;
       }
       w[j].x=a;
       w[j].y=b;
       k=j;
       solve();
    }
    fclose(g);
    return 0;
}
