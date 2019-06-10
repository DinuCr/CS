#include<iostream>
#include<fstream>
using namespace std;
ifstream f("powerpuff.in");
ofstream g("powerpuff.out");
int x,y,z,n,p,i,vp[21][10],vx[21][10],vy[21][10],vz[21][10],x1,yy,z1,j;
int main()
{
    f>>x>>y>>z>>n;
    for(i=1;i<=n;i++)
    {
        f>>p;
        while(p!=0)
        {
            vp[i][p%10]++;
            p/=10;
        }
        x1=x;
        while(x1!=0)
        {
            vx[i][x1%10]++;
            x1/=10;
        }
        yy=y;
        while(yy!=0)
        {
            vy[i][yy%10]++;
            yy/=10;
        }
        z1=z;
        while(z1!=0)
        {
            vz[i][z1%10]++;
            z1/=10;
        }
        for(j=1;j<=9;j++)
        {
            if(vp[i][j]!=0 && vx[i][j]==0)
                x-=j*vp[i][j];
            else
                if(vx[i][j]!=0 && vp[i][j]==0)
                x+=j*vx[i][j];

            if(vp[i][j]!=0 && vy[i][j]==0)
                y-=j*vp[i][j];
            else
                if(vy[i][j]!=0 && vp[i][j]==0)
                y+=j*vy[i][j];

            if(vp[i][j]!=0 && vz[i][j]==0)
                z-=j*vp[i][j];
            else
                if(vz[i][j]!=0 && vp[i][j]==0)
                z+=j*vz[i][j];
        }
    }
    g<<x<<endl<<y<<endl<<z;
    f.close();
    g.close();
    return 0;
}

