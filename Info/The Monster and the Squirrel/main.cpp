#include <iostream>

using namespace std;

long long  n,nr;

int main()
{
    cin>>n;
    if(n==3)
        cout<<1;
    else
    {
        nr=1;
        nr+=3*(n-3);
        nr+=(n-3)*(n-4);
        cout<<nr;
    }
}
