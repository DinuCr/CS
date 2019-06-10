#include <iostream>

using namespace std;
int qs(int ls,int ld,int a[])
{
    int i,j,m,x;
    m=(ls+ld)/2;
    x=a[m];i=ls;j=ld;
    do
    {
        while(a[i]<x)
        i++;
        while(a[j]>x)
        j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            j--;
            i++;
        }
    }while(i<=j);
    return a[m];
}
int main()
{
    int n,i,v[100];
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>v[i];
    cout<<qs(1,n,v);
}
