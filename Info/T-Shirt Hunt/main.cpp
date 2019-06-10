#include <iostream>
#include <cmath>

using namespace std;

int p,x,y,x2;

bool is_in(int x)
{
    x = x/50 %475;
    for(int i=1; i<=25; ++i)
    {
        x = (x*96 + 42)%475;
        if(x+26==p)
            return 1;
    }
    return 0;
}

int main()
{
    cin>>p>>x>>y;
    x2=x;
    while(x2-50>=y)
    {
        x2-=50;
        if(is_in(x2))
        {
            cout<<0;
            return 0;
        }
    }
    float ans = 0;
    while(!is_in(x))
    {
        ans+=0.5;
        x+=50;
    }
    cout<<ceil(ans);
}

