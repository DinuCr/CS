#include<iostream>
#include<fstream>
using namespace std;
ifstream f("paralel.in");
ofstream g("paralel.out");
typedef struct coord
{
    int x,y;
};
int i,j,n,p,k,ok,s,z,x,y;
coord v[501];
int w[124760];
void qsort(int ls,int ld)
{
    int m,i,j,z;
    m=(ls+ls)/2;
    i=ls;
    j=ld;
    z=w[m];
    do
    {
        while(w[i]<z)
            i++;
        while(w[j]>z)
            j--;
        if(i<=j)
        {
            swap(w[i],w[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(i<ld)
        qsort(i,ld);
    if(j>ls)
        qsort(ls,j);
}
int main()
{
   f>>n;
   for(i=1;i<=n;i++)
        f>>v[i].x>>v[i].y;
   for(i=1;i<n;i++)
   for(j=i+1;j<=n;j++)
   {
       k++;
       x=v[i].x+v[j].x;
       y=v[i].y+v[j].y;
       w[k]=x*10000+y;
   }
   ok=true;
   qsort(1,k);
   i=1;
   while(i<=k)
   {
       j=i;
       while(w[i]==w[j+1])
        j++;
       s+=(j-i)*(j-i+1)/2;
       i=j+1;
   }
   g<<s;
   f.close();
   g.close();
   return 0;
}
