#include <iostream>

using namespace std;

long long l1,l2,r1,r2,k,d;

int main()
{
    cin>>l1>>r1>>l2>>r2>>k;
    if(r2>=l1 && r2<=r1)
    {
        d=r2-max(l1,l2)+1;
        if(k<=r2 && k>=max(l1,l2))
        --d;
    }
    else
    if(l2>=l1 && l2<=r1)
    {
        d=min(r1,r2)-l2+1;
        if(k<=min(r1,r2) && k>=l2)
            --d;
    }
    else
    if(r1>=l2 && r1<=r2)
    {
        d=r1-max(l1,l2)+1;
        if(k<=r1 && k>=max(l1,l2))
        --d;
    }
    else
    if(l1>=l2 && l1<=r2)
    {
        d=min(r1,r2)-l1+1;
        if(k<=min(r1,r2) && k>=l1)
            --d;
    }
    cout<<d;
}
