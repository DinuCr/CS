#include<iostream>
#include<fstream>
using namespace std;
ifstream f("pseudobil.in");
ofstream g("pseudobil.out");
float v[1001][2],w[1001][2],n,k,d,m,nr,a,y2,y3,y4,x1,x2,x3,x4,c1,c2;
int i,p,j,s;
float f1(float x,float y)
{
    return (y-a)*(x2-x1)-(x-x1)*(y2-a);
}
float f2(float x,float y)
{
    return (y-y2)*(x3-x2)-(x-x2)*(y3-y2);
}
float f3(float x,float y)
{
    return (y-y3)*(x4-x3)-(x-x3)*(y4-y3);
}
float f4(float x,float y)
{
    return (y-y4)*(x1-x4)-(x-x4)*(a-y4);
}
bool cond(float a,float b)
{
    if(f1(c1,c2)*f1(a,b)<0)
    return 0;
    if(f2(c1,c2)*f2(a,b)<0)
    return 0;
    if(f3(c1,c2)*f3(a,b)<0)
    return 0;
    if(f4(c1,c2)*f4(a,b)<0)
    return 0;
    return 1;
}
int main()
{
    f>>p>>n>>k>>d;
    if(p==1)
    {
        s=d-1;
        d-=2;
        i=1;
        while(i<=d)
        {
            s+=i*2;
            i+=2;
        }
        g<<s;
    }
    else
    {
        for(i=1;i<=k;i++)
        {
            f>>v[i][0]>>v[i][1];
            v[i][0]-=0.5;
            v[i][1]-=0.5;
        }
        f>>m;
        for(i=1;i<=m;i++)
        {
            f>>w[i][0]>>w[i][1];
            w[i][0]-=0.5;
            w[i][1]-=0.5;
        }
        for(i=1;i<=m;i++)
        {
            nr=0;
            c1=w[i][0]+d/2;
            c2=w[i][1];
            x1=w[i][0];
            a=w[i][1];
            x2=x1+d/2;
            y2=a+d/2;
            x3=x1+d;
            y3=a;
            x4=x2;
            y4=a-d/2;
            for(j=1;j<=k;j++)
            if(cond(v[j][0],v[j][1])==1)
                nr++;
            g<<nr<<'\n';
        }
    }
    f.close();
    g.close();
    return 0;
}
