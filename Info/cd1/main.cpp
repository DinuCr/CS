#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cd1.in");
ofstream g("cd1.out");
int v[301],x,y,s,p,n,i;
int main()
{
    f>>n>>s;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        v[i]-=x;
        v[y]+=x;
    }
    s/=n;
    s--;
    p=1;
    for(i=1;i<=n;i++)
    {
        p*=s-v[i];
        p%=9901;
    }
    g<<p;
    f.close();
    g.close();
    return 0;
}
