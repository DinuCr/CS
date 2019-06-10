#include <iostream>

using namespace std;

long long n,i,j,nr,p,x,d;

int main()
{
    cin>>n;
    p=0;
    for(i=1; i<=n; ++i)
    {
        cin>>x;
        if(x==0)
        {
            d=i-p;
            nr+=(d-1)*d/2;
            p=i;
        }
    }
    --i;
    d=i-p;
    nr+=(d+1)*d/2;

    cout<<nr;
}
