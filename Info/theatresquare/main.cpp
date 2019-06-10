#include<iostream>
using namespace std;
long long m,n,nr,a;
int main()
{
    cin>>m>>n>>a;
    if(a<=n && a<=m)
    {
    nr=(m/a)*(n/a);
    if(m%a!=0)
        nr+=n/a;
    if(n%a!=0)
        nr+=m/a;
    if(n%a!=0 && m%a!=0)
        nr++;
    cout<<nr;
    }
    else
    cout<<'1';
}
