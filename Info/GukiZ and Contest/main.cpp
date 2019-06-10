#include <iostream>

using namespace std;
typedef struct pct
{
    int x,y,z;
};
pct v[2001];
int i,n,nr,nr1;
void qsort(int ls,int ld)
{
    int m,i,j,z;
    m=(ls+ls)/2;
    i=ls;
    j=ld;
    z=v[m].x;
    do
    {
        while(v[i].x<z)
            i++;
        while(v[j].x>z)
            j--;
        if(i<=j)
        {
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(i<ld)
        qsort(i,ld);
    if(j>ls)
        qsort(ls,j);
}
void qsort1(int ls,int ld)
{
    int m,i,j,z;
    m=(ls+ls)/2;
    i=ls;
    j=ld;
    z=v[m].y;
    do
    {
        while(v[i].y<z)
            i++;
        while(v[j].y>z)
            j--;
        if(i<=j)
        {
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(i<ld)
        qsort1(i,ld);
    if(j>ls)
        qsort1(ls,j);
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>v[i].x;
        v[i].y=i;
    }
    qsort(1,n);
    i=n;nr=1;
    v[n].z=nr;
    for(i=n-1;i>0;i--)
    {
        if(v[i].x!=v[i+1].x)
        {
            nr++;
            nr+=nr1;
            nr1=0;
        }
        else
        {
            nr1++;
        }
        v[i].z=nr;

    }
    qsort1(1,n);
    for(i=1;i<=n;i++)
        cout<<v[i].z<<' ';
    return 0;
}
