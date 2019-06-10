#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("romb.in");
ofstream fout("romb.out");

int t,dx,dy,k,x,y;

inline bool sgn(double dx,double dy,double x,double y)
{
    if((dx-x)*dy-dx*(dy-y)>0)
        return 1;
    return 0;
}

void compute(long long ans,int k,double dx,double dy,double x,double y)
{
    if(k==0)
        {
            fout<<ans<<'\n';
            return;
        }
    if(sgn(dx,dy,x,y)==sgn(dx,dy,0,dy))
    {
        if(sgn(-dx,dy,x,y)==sgn(-dx,dy,0,dy))
            compute(ans*4-3,k-1,(double)dx/2,(double)dy/2,x,y-dy);
        else
            compute(ans*4-2,k-1,(double)dx/2,(double)dy/2,x+dx,y);
    }
    else
    {
        if(sgn(dx,-dy,x,y)==sgn(dx,-dy,dx,0))
            compute(ans*4,k-1,(double)dx/2,(double)dy/2,x-dx,y);
        else
            compute(ans*4-1,k-1,(double)dx/2,(double)dy/2,x,y+dy);
    }
}

int main()
{
    fin>>t;
    while(t--)
    {
        fin>>dx>>dy>>k>>x>>y;
        compute(1,k,(double)dx/2,(double)dy/2,x,y);
    }
}
