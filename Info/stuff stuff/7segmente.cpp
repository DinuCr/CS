#include<iostream>
#include<fstream>
using namespace std;
ifstream f("7segmente.in");
ofstream g("7segmente.out");
unsigned long long n,ok,n2,ok1;
long long a[25],b[25],s,j,i,t,p,nr;
int putere(unsigned long long x)
{
    int s=0;
    while(x>0)
    {
        switch(x%10)
        {
        case 1:
            s+=2;
            break;
        case 2:
            s+=5;
            break;
        case 3:
            s+=5;
            break;
        case 4:
            s+=4;
            break;
        case 5:
            s+=5;
            break;
        case 6:
            s+=6;
            break;
        case 7:
            s+=3;
            break;
        case 8:
            s+=7;
            break;
        case 9:
            s+=6;
            break;
        }
    x/=10;
    }
    return s;
}
int main()
{
    f>>n>>p;
    g<<putere(n)<<' ';
    i=0;
    while(n>0)
    {
        i++;
        a[i]=n%10;
        n/=10;
        nr++;
    }
    t=min(p/2,nr);
    for(i=1;i<=nr/2;i++)
    swap(a[i],a[nr+1-i]);
    for(i=1;i<=t;i++)
    {b[i]=1;p-=2;}
    i=1;
    if(t<nr)
    ok1=true;
    ok=false;
    while(p>0 && i<=t)
    {
        for(j=9;j>0;j--)
        if(ok==false)
            {
            s=0;
            switch(j)
            {
        case 2:
            s+=3;
            break;
        case 3:
            s+=3;
            break;
        case 4:
            s+=2;
            break;
        case 5:
            s+=3;
            break;
        case 6:
            s+=4;
            break;
        case 7:
            s+=1;
            break;
        case 8:
            s+=5;
            break;
        case 9:
            s+=4;
            break;
        }
        if((j<=a[i] || ok1==true) && p-s>=0)
        {
            b[i]=j;
            if(j<a[i])ok=true;
            p-=s;
            break;
        }
        }
        else
        {
               s=0;
            switch(j)
            {
        case 2:
            s+=3;
            break;
        case 3:
            s+=3;
            break;
        case 4:
            s+=2;
            break;
        case 5:
            s+=3;
            break;
        case 6:
            s+=4;
            break;
        case 7:
            s+=1;
            break;
        case 8:
            s+=5;
            break;
        case 9:
            s+=4;
            break;
        }
            if(p-s>=0){b[i]=j;p-=s;break;}
        }
        i++;
    }
    for(i=1;i<=t;i++)
    g<<b[i];
    f.close();
    g.close();
    return 0;
}
