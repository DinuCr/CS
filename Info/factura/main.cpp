#include<iostream>
#include<fstream>
using namespace std;
ifstream f("factura.in");
ofstream g("factura.out");
int v[2000],i,j,a,b,x,t,s,n;
char c1,c2;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>c1>>c2;
        a=(c1-'0')*10+(c2-'0');
        f>>c1;
        f>>c1>>c2>>t;
        b=(c1-'0')*10+(c2-'0');
        x=a*60+b;
        for(j=x+1;j<=x+t;j++)
            v[j]++;
    }
    for(i=1;i<=420;i++)
        s+=v[i]*5;
    for(i=421;i<=1140;i++)
        s+=v[i]*10;
    for(i=1141;i<1500;i++)
        s+=v[i]*5;
    g<<s;
    f.close();
    g.close();
    return 0;
}
