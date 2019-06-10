#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#define pi 3.14159265

ifstream fin("pie.in");
ofstream fout("pie.out");

double dist(double a,double b,double c,double d)
{
    return (double)sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

double tcos(double ax,double ay,double bx,double by,double cx,double cy)
{
    double a = dist(bx,by,cx,cy);
    double b = dist(ax,ay,cx,cy);
    double c = dist(bx,by,ax,ay);
    double coss = (double)(b*b+c*c-a*a)/(2*b*c);
    return (double)acos(coss) * 180/pi;
}

int main()
{
    int t,x,y;
    fin>>t;
    double p;
    int cnt = 0;
    while(++cnt<=t)
    {
        fin>>p>>x>>y;
        p = p*360/100;
        if(dist(50,50,x,y)>50)
            fout<<"Case #"<<cnt<<": white\n";
        else
        {
            if(x>=50)
            {
                if(abs(tcos(50,50,50,100,x,y)-p)<=0.000001 || tcos(50,50,50,100,x,y)<=p)
                    fout<<"Case #"<<cnt<<": black\n";
                else
                    fout<<"Case #"<<cnt<<": white\n";
            }
            else
            {
                if(abs(360-tcos(50,50,50,100,x,y)-p)<=0.000001 || 360-tcos(50,50,50,100,x,y)<=p)
                    fout<<"Case #"<<cnt<<": black\n";
                else
                    fout<<"Case #"<<cnt<<": white\n";
            }
        }

    }
}
