#include<iostream>
using namespace std;
int n,a[100];
void qsort(int ls,int ld)
{
    int m,x,i,j,aux;
    m=(ls+ld)/2;
    x=a[m];
    i=ls;
    j=ld;
    do
    {
        while(a[i]<x)
        i++;
        while(a[j]>x)
        j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(j>ls)qsort(ls,j);
    if(i<ld)qsort(i,ld);
}
int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>a[i];
    qsort(1,n);
    for(i=1;i<=n;i++)
    cout<<a[i]<<' ';
    return 0;
}
