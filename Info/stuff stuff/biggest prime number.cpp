#include<iostream>
#include<cmath>
using namespace std;
int ok,i,d;
int main()
{
    for(i=100000;i>0;i--)
    {
        ok=true;
        if(i%2==0)
            ok=false;
        else
            for(d=3;d<=sqrt(i);d+=2)
            if(i%d==0)
            {
                ok=false;
                break;
            }
        if(ok==true)
        {
            cout<<i;
            break;
        }
    }
    return 0;
}
