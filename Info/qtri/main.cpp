#include <iostream>
#include <cstdio>

using namespace std;

#define DIM 10000
char buff[DIM];
int poz=0;

void citeste(long double &numar)
{
     numar = 0;
     char semn='+';
     while (buff[poz] < '0' || buff[poz] > '9')
     {
          semn = buff[poz];
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     }
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     }
     if (semn == '-')
          numar = -numar;
}

long double ax,ay,bx,by,x,y,dx,dy,q;

int f()
{
    long double cx=(ax+bx+dx)/3;
    long double cy=(ay+by+dy)/3;
    if(((ax-x)*(by-ay)-(bx-ax)*(ay-y))*((ax-cx)*(by-ay)-(bx-ax)*(ay-cy))>=0 &&
       ((ax-x)*(dy-ay)-(dx-ax)*(ay-y))*((ax-cx)*(dy-ay)-(dx-ax)*(ay-cy))>=0 &&
       ((dx-x)*(by-dy)-(bx-dx)*(dy-y))*((dx-cx)*(by-dy)-(bx-dx)*(dy-cy))>=0)
            return 1;
    return 0;
}

int main()
{
    freopen("qtri.in","r",stdin);
    freopen("qtri.out","w",stdout);
    citeste(q);
    while(q--)
    {
        citeste(ax);
        citeste(ay);
        citeste(bx);
        citeste(by);
        citeste(dx);
        citeste(dy);
        citeste(x);
        citeste(y);
        if(f())
            printf("DA\n");
        else
            printf("NU\n");
    }
}
