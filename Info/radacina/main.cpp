#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double x,v[10],m,p,dr,st,limita=0.00000000000001,prec=0.00001;
int n;
ifstream fi("radacina.in");
ofstream g("radacina.out");
inline double f(double x)
{
    double s=0;
    for(int i=1; i<=n+1; i++)
        s+=pow(x,n-i+1)*v[i];
    return s;
}
int main()
{
    fi>>n;
    for(int i=n+1; i>0; i--)
        fi>>v[i];
    st=-20;
    dr=20;
    if(f(st)>0)
        swap(st,dr);

    while(true)
    {
        m=(st+dr)/2;
        p=f(m);
        if(abs(p)<=prec)
        {
            g<<m;
            break;
        }
        else if(p<0)
            st=m;
        else
            dr=m;
    }
}
