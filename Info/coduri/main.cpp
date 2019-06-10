#include<iostream>
#include<fstream>
using namespace std;
ifstream f("coduri.in");
ofstream g("coduri.out");
long long s,n,i;
int main()
{
    cin>>n;
    s=n*(n+1)*(2*n+1)/6;
    s=s*s*s*s;
    for(i=1;i<=n;i++)
        cout<<s*i<<'\n';
}
