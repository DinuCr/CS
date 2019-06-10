#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;


#define DIM 10000
char buff[DIM];
int poz=0;

void citeste(int &numar)
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


int v[550000],w[550000],n,k,i1,i2,i,mx,p1,p2;

int main()
{
    freopen("secventa.in","r",stdin);
    freopen("secventa.out","w",stdout);

    cin>>n>>k;
    p1=1;
    p2=0;

    for(i=1; i<=n; ++i)
        citeste(w[i]);

    mx=-300000;
    for(i=1; i<=n; ++i)
    {
        if(p2<p1)
        {
            --p1;
            v[p1]=i;
        }
        else
        {
            if(i-v[p1]>=k)
                ++p1;
            while(w[i]<w[v[p2]] && p2>=p1)
                --p2;
            v[++p2]=i;
        }
        if(w[v[p1]]>mx && i>=k)
        {
            mx=w[v[p1]];
            i1=i-k+1;
            i2=i;
        }
    }
    cout<<i1<<' '<<i2<<' '<<mx;
}
