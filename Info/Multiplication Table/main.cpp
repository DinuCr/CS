#include <iostream>
#include<cmath>
using namespace std;
long long n,m,i,x,nr;
int main()
{
    cin>>n>>m;
    x=min((long long)sqrt(m),n);
    for(i=1;i<=x;i++)
    {
        if(m%i==0 && m/i<=n)
            nr+=2-(sqrt(m)==i);
    }
    cout<<nr;
}
