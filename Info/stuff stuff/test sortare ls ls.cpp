#include<iostream>
#include<fstream>
using namespace std;
ifstream f("testls.in");
int i,v[100],n;
void qsort(int ls,int ld)
{
    int i,j,m,x;
    i=ls;
    j=ld;
    m=(ls+ld)/2;
    x=v[m];
    do
    {
        while(v[i]<x)
            i++;
        while(v[j]>x)
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
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
        f>>v[i];
    qsort(1,n);
    for(i=1;i<=n;i++)
        cout<<v[i]<<' ';
    return 0;
    f.close();
}
