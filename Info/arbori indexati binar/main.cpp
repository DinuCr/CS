#include <fstream>
using namespace std;
#define zeros(x) ((x^(x-1))&x)
int v[100010],n,m,i,p,x,a,b,k;
void add(int ls,int x)
{
    for(;ls<=n;ls+=zeros(ls))
        v[ls]+=x;
}
int compute(int x)
{
    int s=0;
    for(;x>0;x-=zeros(x))
        s+=v[x];
    return s;
}
int bs(int ls,int ld,int x)
{
    if(ls>=ld)
    {
        if(compute(ls)==x)
        return ls;
        else
            return -1;
    }
    else
    {
        int m=compute((ls+ld)/2);
        if(m==x)
            return (ls+ld)/2;
        if(m<x)
            return bs((ls+ld)/2+1,ld,x);
        return bs(ls,(ls+ld)/2-1,x);
    }
}
ifstream f("aib.in");
ofstream g("aib.out");
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
            add(a,b);
            break;
        case 1:
            f>>a>>b;
            g<<compute(b)-compute(a-1)<<'\n';
            break;
        case 2:
            f>>k;
            g<<bs(1,n,k)<<'\n';
            break;
        }
    }
}
