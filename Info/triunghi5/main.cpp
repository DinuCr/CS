#include <iostream>
#include <fstream>
using namespace std;
ifstream f("triunghi5.in");
ofstream g("triunghi5.out");
int v1,n,k,mn,i,j,a[50],l,b[50],s,nr=1,x;
void qsort(int inf, int sup)
{
  int x, i, j, t;
  i = inf;
  j = sup;
  x = a[(i + j) / 2];
  do {
    while ( (i < sup) && (a[i] < x) ) i++;
    while ( (j > inf) &&(a[j] > x) ) j--;
    if ( i<= j ) {
      t = a[i];
      a[i] = a[j];
      a[j] = t;
      i++;
      j--;
    }
  } while ( i <= j );
  if ( inf < j ) qsort(inf, j);
  if ( i < sup ) qsort(i, sup);
}
int main()
{
    f>>v1>>n>>k;
    mn=2000000000;
    for(i=1;i<=n;i++)
    {
        f>>a[i];b[i]=a[i];
        if(a[i]<mn) mn=a[i];
        else if(a[i]==mn) nr++;
    }
    if(v1==1)
    {
        b[1]=mn;b[2]=mn;
        i=1;j=1;
        for(l=3;l<=k;l++)
        {
            s=i+j;
            i=j;j=s;
            b[l]=mn*s;
        }
     for(i=1;i<=k;i++) g<<b[i]<<' ';
    }

    else
    {
        qsort(1,n);
        int b1,b2,b3;
        i=1;nr=n;b1=0;b2=1;
        if(b1+b2+a[i]>a[i+1])
        {
            b1=a[i];
            b2=a[i+1];
        }
        else {nr++;b[nr]=1;}

        while(nr<=k && i<=n)
        {
            b3=b2+b1;
            if(b3+b2<=a[i])
            {
                nr++;
                b[nr]=b3;
                b1=b2;
                b2=b3;
            }
            else
            {
                b1=b2;
                b2=a[i];
                i++;
            }
        }
        if(nr<=k)
        {
            b1=max(a[n-1],b[nr]);
            b2=a[n];
            while(nr<=k)
            {
                b3=b2+b1;
                nr++;
                b[nr]=b3;
                b1=b2;b2=b3;
            }
        }
        for(i=1;i<=k;i++)
    g<<b[i]<<" ";


    }
}
