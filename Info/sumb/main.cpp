#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
ifstream f("sumb.in");
ofstream g("sumb.out");
int a[205],b[205],c[205],r[205],mx,i,k,ok;
char sir[205];
void adunare(int k)
{
    int mx,t,i;
    mx=max(a[0],b[0]);
    c[0]=0;
    t=0;
    for(i=1;i<=mx;i++)
    {
        t+=a[i]+b[i];
        c[++c[0]]=t%k;
        t/=k;
    }
    if(t>0)
        c[++c[0]]=t;
}
int main()
{
    f.getline(sir,202);
    a[0]=strlen(sir);
    for(i=1;i<=a[0];i++)
        a[a[0]-i+1]=sir[i-1]-'0';
    f.getline(sir,202);
    b[0]=strlen(sir);
    for(i=1;i<=b[0];i++)
        b[b[0]-i+1]=sir[i-1]-'0';
    f.getline(sir,202);
    r[0]=strlen(sir);
    for(i=1;i<=r[0];i++)
        r[r[0]-i+1]=sir[i-1]-'0';
    for(i=1;i<=a[0];i++)
        mx=max(mx,a[i]);
    for(i=1;i<=b[0];i++)
        mx=max(mx,b[i]);
    for(i=1;i<=r[0];i++)
        mx=max(mx,r[i]);
    ok=0;
    if(mx==0)
        mx++;
    for(k=mx+1;k<=20 && ok==0;k++)
    {
        adunare(k);
        ok=1;
        for(i=0;i<=c[0];i++)
            if(c[i]!=r[i])
        {
            ok=0;
            break;
        }
    }
    if(ok==0)
        g<<'0';
    else
        g<<k-1;
    f.close();
    g.close();
    return 0;
}
