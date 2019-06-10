#include <iostream>

using namespace std;

int main()
{
    int i,n,x;
    std::ios::sync_with_stdio(0);
    cin>>n;
    int last = 0;
    int cnt = 1;
    int ok = -1;
    for(i=1; i<=n; ++i)
    {
        cin>>x;
        if(ok==-1)
        {
            last = x;
            ok = 0;
        }
        else
        if(ok == 0)
        {
            if(last>x)
                ok=1,last = x;
            else
            if(last<x)
                ok=2,last = x;
        }
        else
        if(ok == 1)
        {
            if(last<x)
                ok=0,++cnt,last=x;
            else
                last = x;
        }
        else
        if(ok == 2)
        {
            if(last>x)
                ok=0,++cnt,last=x;
            else
                last = x;
        }
    }
    cout<<cnt;
}
