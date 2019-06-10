#include<iostream>
#include<fstream>
using namespace std;
ifstream f("pseudobil.in");
ofstream g("pseudobil.out");
float v[1000][2],w[1000][2],x,y,x1,yy,x2,y2,x3,x4,y3,y4,x0,yyy,n,k,d,m;
int i,p,j,s;
float f1(float x,float y)
{
    return x*(y2-yy)-y*(x2-x1)-x1*y2+yy*x2;
}
float f2(float x,float y)
{
    return x*(y3-y2)-y*(x3-x2)-x2*y3+y2*x3;
}
float f3(float x,float y)
{
    return x*(y4-y3)-y*(x4-x3)-x3*y4+y3*x4;
}
float f4(float x,float y)
{
    return x*(yy-y4)-y*(x1-x4)-x4*yy+y4*x1;
}
bool cond(float px,float py)
{
    if(f1(px,py)*f1(x0,yyy)<0)
    return 0;
    if(f2(px,py)*f2(x0,yyy)<0)
    return 0;
    if(f3(px,py)*f3(x0,yyy)<0)
    return 0;
    if(f4(px,py)*f4(x0,yyy)<0)
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
            s+=i;
            i+=2;
        }
        g<<s;
    }
    else
    {
        for(i=1;i<=k;i++)
        {
            f>>v[i][1]>>v[i][0];
            v[i][0]-=0.5;
            v[i][1]-=0.5;
        }
        f>>m;
        for(i=1;i<=m;i++)
        {
            f>>w[i][1]>>w[i][0];
            w[i][0]-=0.5;
            w[i][1]-=0.5;
        }
        for(i=1;i<=m;i++)
        {
            int nr=0;
            x1=w[i][0];
            yy=w[i][1];
            x2=x1+d/2;
            y2=yy+d/2;
            x3=x1+d;
            y3=yy;
            x4=x1+d/2;
            y4=yy-d/2;
            x0=x1;
            yyy=y2;
            for(j=1;j<=k;j++)
            {
                if(cond(v[j][0],v[j][1])==1)
                nr++;
            }
            g<<nr<<'\n';
        }
    }
    f.close();
    g.close();
    return 0;
}
