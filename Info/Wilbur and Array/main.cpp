#include <iostream>
#include <cmath>
using namespace std;
long long n,x,k,i,nr;
int main()
{
    cin>>n;k=0;nr=0;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x>k)
            nr+=abs(x-k);
        else
            nr+=abs(k-x);
        k=x;
    }
    cout<<nr;
}
