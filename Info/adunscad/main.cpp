#include<iostream>
#include<fstream>
using namespace std;
ifstream f("adunscad.in");
ofstream g("adunscad.out");
char w[21];
int v[21],n,m,i,s,ok,j;
void tipar()
{
    int i;
    if(w[1]=='+')
        g<<v[1];
    else
        g<<w[1]<<v[1];
    for(i=2;i<=m;i++)
    g<<w[i]<<v[i];
}
int main()
{
    f>>n;
    f>>m;
    s=0;
    for(i=1;i<=m;i++)
    {
        f>>v[i];
        s+=v[i];
    }
    if(s<n || -s>n)
        g<<"0";
    else
    {
    if(n+s<s-n)
    {
        for(i=1;i<=m;i++)
            w[i]='-';
        ok=true;
        s=-s;
        if(s==n)
        {
            tipar();
            ok=false;
        }
        while(ok && i>0)
        {
            i=m;
            while(w[i]=='+')
            {
                s-=2*v[i];
                w[i]='-';
                i--;
            }
            s+=2*v[i];
            w[i]='+';
            if(s==n)
            {
                ok=false;
                tipar();
                break;
            }
        }
        if(i==0)
            g<<"0";
    }
    else
    {
         for(i=1;i<=m;i++)
            w[i]='+';
        ok=true;
        if(s==n)
        {
            tipar();
            ok=false;
        }
        while(ok && i>0)
        {
            i=m;
            while(w[i]=='-')
            {
                s+=2*v[i];
                w[i]='+';
                i--;
            }
            s-=2*v[i];
            w[i]='-';
            if(s==n)
            {
                ok=false;
                tipar();
                break;
            }
        }
        if(i==0)
            g<<'0';
    }
    }
    f.close();
    g.close();
    return 0;
}

