#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream f1("roboti.in");
ofstream g("roboti.out");
struct coord
{
    int x,y;
};
coord q[100],w[100];
int ok,n,m,a,b,i,j,d;
bool intersectie(coord a,coord b,coord c,coord d)
{
    int ok=0;
    if(a.x==b.x && c.y==d.y)
    {
        if(min(a.y,b.y)<=c.y && c.y<=max(b.y,a.y))
            if(min(d.x,c.x)<=a.x && a.x<=max(c.x,d.x))
            {
                cout<<a.x<<' '<<c.y<<'\n';
                ok=1;
            }
    }
    else if(a.y==b.y && c.x==d.x)
    {
        if(min(c.y,d.y)<=a.y && a.y<=max(c.y,d.y))
            if(min(a.x,b.x)<=c.x && c.x<=max(a.x,b.x))
            {
                cout<<d.x<<' '<<a.y<<'\n';
                ok=1;
            }
    }
    return ok;
}
int f(coord a,coord b)
{
    return (int)sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
int distanta(coord a,coord b,coord c,coord d)
{
    int mn=f(b,c);
    mn=min(mn,min(min(f(a,d),f(a,c)),f(c,b)));
    if(a.x==b.x && c.x==d.x)
    {
        if((min(c.y,d.y)<=a.y && a.y<=max(c.y,d.y)) || (min(c.y,d.y)<=b.y && b.y<=max(c.y,d.y)))
                mn=min(mn,(int)abs(d.x-a.x)-1);
    }
    else
    if(a.y==b.y && c.y==d.y)
    {
        if((min(d.x,c.x)<=a.x && a.x<=max(c.x,d.x)) || (min(d.x,c.x)<=b.x && b.x<=max(c.x,d.x)))
                mn=min(mn,(int)abs(a.y-d.y)-1);
    }
    return mn;
}
int main()
{
    f1>>a>>b;
    for(i=1; i<=a; i++)
    {
        f1>>q[i].x>>q[i].y;
    }
    for(i=1; i<=b; i++)
    {
        f1>>w[i].x>>w[i].y;
    }
    q[++a]=q[1];
    w[++b]=w[1];
    for(i=1; i<a; i++)
        for(j=1; j<b; j++)
            ok=max(1*intersectie(w[j],w[j+1],q[i],q[i+1]),ok);
    d=distanta(w[1],w[2],q[1],q[2]);
    for(i=1; i<a; i++)
        for(j=1; j<b; j++)
            d=min(distanta(w[j],w[j+1],q[i],q[i+1]),d);
    if(ok)
        d=0;
    cout<<"distanta este "<<d;
}
