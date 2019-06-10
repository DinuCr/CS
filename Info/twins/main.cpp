#include<iostream>
using namespace std;
int n,i,s1,s2,v[101];
void qsort(int ls,int ld)
{
    int m,i,j,z;
    m=(ls+ls)/2;
    i=ls;
    j=ld;
    z=v[m];
    do
    {
        while(v[i]<z)
            i++;
        while(v[j]>z)
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
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    qsort(1,n);
    for(i=1;i<=n;i++)
        s1+=v[i];
    i=n;
    while(s1>=s2)
    {
        s1-=v[i];
        s2+=v[i];
        i--;
    }
    cout<<n-i;
}
