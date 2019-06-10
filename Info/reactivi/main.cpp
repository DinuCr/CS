#include<iostream>
#include<fstream>
using namespace std;
ifstream f("reactivi.in");
ofstream g("reactivi.out");
int mn[8000],mx[8000],i,n,nr,ok,i1,j,mn1,mx1;
void qsort(int ls,int ld)
{
    int i,j,m,x;
    i=ls;
    j=ld;
    m=(ls+ld)/2;
    x=mn[m];
    do
    {
        while(mn[i]<x)
            i++;
        while(mn[j]>x)
            j--;
        if(i<=j)
        {
            swap(mn[i],mn[j]);
            swap(mx[i],mx[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(j>ls)
        qsort(ls,j);
    if(i<ld)
        qsort(i,ld);
}
void qsort1(int ls,int ld)
{
    int i,j,m,x;
    i=ls;
    j=ld;
    m=(ls+ld)/2;
    x=mx[m];
    do
    {
        while(mx[i]>x)
            i++;
        while(mx[j]<x)
            j--;
        if(i<=j)
        {
            swap(mn[i],mn[j]);
            swap(mx[i],mx[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(j>ls)
        qsort1(ls,j);
    if(i<ld)
        qsort1(i,ld);
}
int main()
{
    f>>n;
    for(i=0;i<n;i++)
    f>>mn[i]>>mx[i];
    qsort(0,n-1);
    nr=1;
    i=1;
    while(i<n)
    {
        j=i;
        while(mn[i]==mn[j+1])
            j++;
        qsort1(i,j);
        i=j+1;
    }
    mx1=mx[0];
    mn1=mn[0];
    for(i=1;i<n;i++)
    {
        if(mn[i]<=mx1)
        {
            mx1=min(mx1,mx[i]);
            mn1=mn[i];
        }
        else
        {
            nr++;
            mn1=mn[i];
            mx1=mx[i];
        }
    }
    g<<nr;
    f.close();
    g.close();
    return 0;
}
