#include <iostream>

using namespace std;

long long a,mx,ok,i,j,k,x;

long long gdc(long long a,long long b)
{
    if(b==0)
        return a;
    else
    return gdc(b,a%b);
}

int main()
{
    cin>>a;
    mx=0;
    ok=1;
    for(i=a; i>max(a-50,0*1LL); --i)
        for(j=i; j>max(a-50,0*1LL); --j)
            for(k=j; k>max(a-50,0*1LL); --k)
            {
                x = i*j/(gdc(i,j));
                x = x*k/(gdc(x,k));
                mx=max(mx,x);
            }
    cout<<mx;
}
