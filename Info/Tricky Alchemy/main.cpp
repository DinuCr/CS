#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);


    ll a,b,c,x,y,z;

    cin>>a>>c>>x>>y>>z;
    b=0;

    if(y<=a)
        a-=y;
    else
        b+=y-a,a=0;
    if(y<=c)
        c-=y;
    else
        b+=y-c,c=0;

    if(x<=a/2)
    {
        a-=x*2;
        x=0;
    }
    else
    {
        x-=a/2;
        a=a-(ll)a/2*2;
        b+=x*2-a;
        a=0;
    }
    if(z<=c/3)
    {
        c-=z*3;
        z=0;
    }
    else
    {
        z-=c/3;
        c-=(ll)c/3*3;
        b+=z*3-c;
    }
    cout<<b;
}
