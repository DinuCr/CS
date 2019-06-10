#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define pb push_back
#define po pop_back
using namespace std;
ifstream f("infasuratoare.in");
ofstream g("infasuratoare.out");
double x,y;
int i,n,k;
typedef struct co
{
    double x,y;
};
co mn;
vector <co> v;
vector <co> s;
bool compare(co a,co b)
{
    return (a.y-mn.y)*(b.x-mn.x)<(b.y-mn.y)*(a.x-mn.x);
}
bool rotdr(co a,co b,co c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x)<=0;
}
int main()
{
    f>>n;
    co a;
    mn.x=1000000000;
    mn.y=1000000000;

    for(i=1;i<=n;i++)
    {
        f>>a.x>>a.y;
        if(mn.y>a.y)
            mn=a,k=i;
        else
        if(mn.y==a.y && mn.x>a.x)
            mn=a,k=i;
        v.pb(a);
    }
    swap(v[k-1],v.back());
    v.po();
    sort(v.begin(),v.end(),compare);
    s.pb(mn);
    s.pb(v[0]);
    s.pb(v[1]);
    for(i=2;i<v.size();i++)
    {
        while(rotdr(s[s.size()-2],s[s.size()-1],v[i]))
            s.po();
        s.pb(v[i]);
    }
    g<<s.size()<<'\n';
    for(i=0;i<s.size();i++)
        g<<setprecision(13)<<fixed<<s[i].x<<' '<<s[i].y<<'\n';
}
