#include <iostream>

using namespace std;

long long x1,x2,x4,x5,p,r,n,a,b,c,d;

bool valid()
{
    if(x1>n || x2>n || x4>n || x5>n || x1<1 || x2<1 || x4<1 || x5<1)
        return 0;
    return 1;
}

int main()
{
    cin>>n>>a>>b>>c>>d;
    int mx=n+a+b;
    for(p=1; p<=mx; ++p)
    {
        x1=p-a-b;
        x2=p-a-c;
        x4=p-b-d;
        x5=p-c-d;
        if(valid())
            r+=n;
    }
    cout<<r;
}
