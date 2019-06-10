#include <iostream>
#include <fstream>
using namespace std;
char x;
ifstream f("expresie2.in");
int s2();
int s1()
{
    f>>x;
    int ok;
    int nr=0,v[1000],z;
    while(x!=')')
    {
        ok=1;
        if(x==',')
        {
            f>>x;
            continue;
        }
        else if(x=='(')
            v[++nr]=s1();
        else if(x=='[')
            v[++nr]=s2();
        else
        {
            if(x=='-')
                v[++nr]=-1,f>>x;
            else
                v[++nr]=1;
            z=x-'0';
            f>>x;
            if(x<='9' && x>='0')
                z=z*10+x-'0',ok=1;
            else
                ok=0;
            v[nr]*=z;
        }
        if(ok)
            f>>x;
    }
    int i=1,j=1;
    int mx=v[1];
    int s=v[1];
    while(j<=nr)
    {
        if(s<0 && i<j)
            s-=v[i++];
        else if(j<nr)
        s+=v[++j];
        else
        j++;
        mx=max(s,mx);
    }
    return mx;
}
int s2()
{
    int ok,v[200],nr,n=0;
    for(int i=1; i<200; i++)
        v[i]=0;
    f>>x;
    while(x!=']')
    {
        ok=1;
        if(x==',')
        {
            f>>x;
            continue;
        }
        if(x=='(')
            v[s1()+100]++,n++;
        else if(x=='[')
            v[s2()+100]++,n++;
        else
        {
            if(x=='-')
            {
                f>>x;
                nr=-(x-'0');
                f>>x;
                if(x<='9' && x>='0')
                    nr=nr*10-(x-'0'),ok=1;
                else
                    ok=0;
                v[nr+100]++;n++;
            }
            else
            {
                nr=x-'0';
                f>>x;
                if(x<='9' && x>='0')
                    nr=nr*10+x-'0',ok=1;
                else
                    ok=0;
                v[nr+100]++;n++;
            }
        }
        if(ok)
        f>>x;
    }
    nr=(n+1)/2;
    for(int i=1;i<200;i++)
    {
        nr-=v[i];
        if(nr<=0)
        return i-100;
    }
}
int suma()
{
    int nr=0,ok,s=0;
    f>>x;
    while(!f.eof())
    {
        ok=1;
        if(x==',')
        {
            f>>x;
            continue;
        }
        if(x<='9' && x>'0')
        {
            nr=x-'0';
            f>>x;
            if(x<='9' && x>'0' && !f.eof())
                nr=nr*10+x-'0',ok=1;
            else
                ok=0;
            s+=nr;
        }
        else if(x=='-')
        {
            f>>x;
            nr=-(x-'0');
            f>>x;
            if(x<='9' && x>='0')
                nr=nr*10-(x-'0'),ok=1;
            else
                ok=0;
            s+=nr;
        }
        else if(x=='(')
            s+=s1();
        else
            s+=s2();
        if(ok)
            f>>x;
    }
    return s;
}
int main()
{
    ifstream g("expresie2.in");
    int nr=0,s=0;
    g>>x;
    while(!g.eof())
    {
        if(x==',')
            nr++;
        g>>x;
    }
    ofstream a("expresie2.out");
    a<<nr+1<<'\n';
    s=suma();
    a<<s;
}
