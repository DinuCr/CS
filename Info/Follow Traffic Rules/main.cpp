#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double a,v,l,d,w,t,vf,v1,xf,x,d1;
double timp(double v0,double l)
{
    double x,t=0;
    x=(v*v-v0*v0)/(2*a);
    if(x<=l)
    {
        t+=(double)(l-x)/v + x/((v+v0)/2);
        return t;
    }
    else
    {
        v=(double)sqrt(2*a*l+v0*v0);
        t=(double)l/((double)(v+v0)/2);
        return t;
    }
}
int main()
{
    cin>>a>>v>>l>>d>>w;
    if(v<=w)
    {
        cout<<setprecision(7)<<fixed<<timp(0,l);
    }
    else
    {
        x=v*v;
        x=(double)x/a;
        x=(double)x/2;
        xf=(double)(v*v-w*w)/(2*a);
        if(x+xf<=d)
        {
            t=x/(v/2)+xf/((v+w)/2)+(d-x-xf)/v;
            t+=timp(w,l-d);
            cout<<setprecision(7)<<fixed<<t;
        }
        else
        {
            vf=sqrt(2*a*d);
            if(vf<=w)
            {
                t=d/(vf/2);
                t+=timp(vf,l-d);
                cout<<setprecision(7)<<fixed<<t;
            }
            else
            {
                d1=(w*w+2*a*d)/(4*a);
                v1=sqrt(2*a*d1);
                t=d1/(v1/2)+(d-d1)/((v1+w)/2);
                t+=timp(w,l-d);
                cout<<setprecision(7)<<fixed<<t;
            }
        }
    }
}
