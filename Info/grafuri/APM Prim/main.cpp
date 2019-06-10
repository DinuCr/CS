#include<stdio.h>
int c[100][100];
int i,j,n,m,nr;
int key[100],viz[100],p[100];
FILE *fin,*fout;
void citire()
{int a;
fin=fopen("prim.in","r");
fscanf(fin,"%d",&n);
for (i=1;i<=n;i++)
for (j=1;j<=n;j++)
if (i==j) c[i][j]=0; else c[i][j]=100;
while (fscanf(fin,"%d%d%d",&i,&j,&a)>0)
 {c[i][j]=a;
  c[j][i]=a;
  }
fclose(fin);
}
int extragemin()
{int min,l,r;
min=100;
r=0;
for (l=1;l<=n;l++)
if (viz[l]==0 && min>key[l])
  {min=key[l];
    r=l;};
viz[r]=1;
nr++;
return r;
}
void prim()
{
nr=1;
for (i=1;i<=n;i++)
viz[i]=0;
viz[1]=0;
for (i=1;i<=n;i++) p[i]=0;
for (i=1;i<=n;i++) key[i]=100;
key[1]=0;
while (nr<n)
 { i=extragemin();
   for (j=1;j<=n;j++)
    if (c[i][j]!=100)
   if (!viz[j] && key[j]>c[i][j])
    {key[j]=c[i][j];
     p[j]=i;
     }
}
}
int main()
{ citire();
prim();
for (i=1;i<=n;i++)
printf("%d %d\n",i,p[i]);
}

