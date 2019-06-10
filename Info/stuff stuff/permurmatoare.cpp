#include<iostream>
using namespace std;
int a[15],i,j,i2,mn,n;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>a[i];
    i=n;
    while(a[i]<a[i-1])
    i--;
    if(i<n)
    {
    mn=a[i+1];
    i2=i+1;
    j=i;
    if(i!=0)
    for(i=j+2;i<=n;i++)
    {
        if(a[i]<mn )
        {
            mn=a[i];
            i2=i;
        }
    }
    swap(a[i2],a[j]);
    i=j;
    j=n;
    while(i<=j)
    {
        swap(a[i],a[j]);
        i++;
        j--;
    }
    }
    else
    swap(a[n],a[n-1]);
    for(i=1;i<=n;i++)
    cout<<a[i]<<' ';
    return 0;
}
