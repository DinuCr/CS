#include <iostream>
#include <cmath>
using namespace std;
int n,nr,v[1010],i,j;
int prim(int x)
{
    int j=sqrt(x),i;
    if(x<2)
        return 0;
    if(x==2)
        return 1;
    if(x%2==0)
        return 0;
    for(i=3;i<=j;i+=2)
        if(x%i==0)
        return 0;
    return 1;
}
int main()
{
    cin>>n;
    for(i=2;i<=n;i++)
        if(prim(i))
        for(j=i;j<=n;j*=i)
            {v[j]=1;nr++;}
    cout<<nr<<'\n';
    for(i=2;i<=n;i++)
        if(v[i])
        cout<<i<<' ';
}
