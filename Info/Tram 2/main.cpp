#include <iostream>
#include <cmath>

using namespace std;

int s,t,t1,x1,t2,x2,p,d;

int main()
{
    cin>>s>>x1>>x2>>t1>>t2>>p>>d;
    if(d==1)
    {
        if(x1<x2)
        {
            if(p<=x1)
            {
                t=(x1-p)*t1;
            }
            else
            {
                t=(s+s-p+x1)*t1;
            }
        }
        else
        {
            t=(s-x1+s-p)*t1;
        }
    }
    else
    {
        if(x1<x2)
        {
            t=(p+x1)*t1;
        }
        else
        {
            if(p>=x1)
            {
                t=(p-x1)*t1;
            }
            else
            {
                t=(p+s+s-x1)*t1;
            }
        }
    }
    cout<<min(abs(x1-x2)*t2,t+abs(x1-x2)*t1);
}
