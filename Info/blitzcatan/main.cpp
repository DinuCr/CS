#include <iostream>
#include <fstream>

using namespace std;

ifstream f("bc.in");
ofstream g("bc.out");

int v[1010],w[10],ok,n,m,i,j,x;

int bs(int s,int d,int x)
{
    if(s>=d)
        return s;
    int m=(s+d)/2;
    if(x==v[m])
        return m;
    if(x>v[m])
       return bs(m+1,d,x);
    return bs(s,m-1,x);
}

void bkt2(int k,int s)
{
    if(ok || k>2)
            return;

    int x=bs(2,1000,s);
    if(v[x]==s)
    {
        w[k]=x;
        m=k;
        ok=1;
        return;
    }

    int i;
    for(i=2; i<1001 && v[i]<s && !ok && k<2; ++i)
    {
        w[k]=i;
        bkt2(k+1,s-v[i]);
    }
}

void bkt3(int k,int s)
{
    if(ok || k>3)
            return;

    int x=bs(2,1000,s);
    if(v[x]==s)
    {
        w[k]=x;
        m=k;
        ok=1;
        return;
    }

    int i;
    for(i=2; i<1001 && v[i]<s && !ok && k<3; ++i)
    {
        w[k]=i;
        bkt3(k+1,s-v[i]);
    }
}

void bkt4(int k,int s)
{
    if(ok || k>4)
            return;

    int x=bs(2,1000,s);
    if(v[x]==s)
    {
        w[k]=x;
        m=k;
        ok=1;
        return;
    }

    int i;
    for(i=2; i<1001 && v[i]<s && !ok && k<4; ++i)
    {
        w[k]=i;
        bkt4(k+1,s-v[i]);
    }
}

int main()
{
    f>>n;

    for(i=2; i<1001; ++i)
        v[i]=(i-1)*i*(i+1);

    for(i=1; i<=n; ++i)
    {
        f>>x;
        ok=0;
        bkt2(1,x);
        if(!ok)
        {
            bkt3(1,x);
            if(!ok)
            {
                bkt4(1,x);
            }
        }
        g<<m<<' ';
        for(j=1; j<=m; ++j)
            g<<w[j]%3<<' '<<w[j]<<' ';
        g<<'\n';
    }
}
