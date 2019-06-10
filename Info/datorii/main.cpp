#include <iostream>
#include <fstream>
using namespace std;
int aib[15010],i,j,x,a,b,n,m,p;
ifstream f("datorii.in");
ofstream g("datorii.out");

inline int zeros(int x)
{
    return ((x^(x-1))&x);
}
void add(int x,int q)
{
    for(int i=x;i<=n;i+=zeros(i))
        aib[i]+=q;
}
int query(int x)
{
    int s=0;
    for(int i=x;i>0;i-=zeros(i))
        s+=aib[i];
    return s;
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>x;
        add(i,x);
    }
    for(i=1;i<=m;i++)
    {
        f>>p;
        switch(p)
        {
        case 0:
            f>>a>>b;
            add(a,-b);
            break;
        case 1:
            f>>a>>b;
            g<<query(b)-query(a-1)<<'\n';
            break;
        }
    }
}
