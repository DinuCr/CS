#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;
ifstream f("ecuatii2.in");
ofstream g("ecuatii2.out");
int n,i,m,k,c1,c2,x1,x2,ok2,nr,ok;
float r;
char v[255];
bool cifra(char x)
{
    if(x<='9' && x>='0')
        return 1;
    return 0;
}
bool semn(char x)
{
    if(x=='-' || x=='+')
        return 1;
    return 0;
}
int main()
{
    f>>m;
    for(k=1;k<=m;k++)
    {
        f>>v;
        n=strlen(v);
        c1=0;
        x1=0;
        c2=0;
        x2=0;
        i=0;
        ok=1;
        ok2=true;
        while(ok2)
        {
            nr=0;
            while(cifra(v[i]))
            {
                nr=nr*10+v[i]-'0';
                i++;
            }
            if(semn(v[i]))
            {
                c1+=nr*ok;
                if(v[i]=='-')
                    ok=-1;
                else
                    ok=1;
                i++;
            }
            else
            if(v[i]=='x')
            {
                x1+=nr*ok;
                if(nr==0)
                    x1+=ok;
                i++;
            }
            else
            if(v[i]=='=')
            {
            c1+=nr*ok;
            ok2=false;
            }
        }
        i++;
        ok=1;
        while(i<n)
        {
            nr=0;
            while(cifra(v[i]))
            {
                nr=nr*10+v[i]-'0';
                i++;
            }
            if(semn(v[i]))
            {
                c2+=nr*ok;
                if(v[i]=='-')
                    ok=-1;
                else
                    ok=1;
                i++;
            }
            else
            if(v[i]=='x')
            {
                x2+=nr*ok;
                if(nr==0)
                    x2+=ok;
                i++;
            }
            else
            {
                c2+=nr*ok;
            }
        }
    if(x1==x2 && c1==c2)
        g<<"infinit\n";
    else
    if(x1==x2)
        g<<"imposibil\n";
    else
    {
        r=float(c2-c1)/(x1-x2);
        g<<fixed<<setprecision(4)<<r<<'\n';
    }
    }
    f.close();
    g.close();
    return 0;
}
