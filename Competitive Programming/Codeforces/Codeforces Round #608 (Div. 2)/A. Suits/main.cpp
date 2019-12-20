#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int ans = 0;
    if(e>f)
    {
        ans+= min(a,d)*e;
        int x = min(a,d);
        a-=x;
        d-=x;
        ans+= min(b, min(c, d)) * f;
    }
    else
    {
        ans += min(b, min(c, d)) *f;
        int x = min(b, min(c, d));
        b-=x;
        c-=x;
        d-=x;
        ans += min(a, d)*e;
    }
    cout<< ans;
}
