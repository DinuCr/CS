#include<iostream>
using namespace std;
int n,i,nr;
char v[100];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(i=1;i<=n;i++)
        if(v[i]==v[i-1])
        nr++;
    cout<<nr;
}
