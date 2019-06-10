#include<iostream>
using namespace std;
int v[101],i,nr,k,n,x;
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        v[x]++;
    }
    i=100;
    while(k>0 && i>0)
    {
        k-=v[i];
        nr+=v[i];
        i--;
    }
    cout<<nr;
}
