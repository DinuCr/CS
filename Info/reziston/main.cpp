#include <iostream>
#include <fstream>
using namespace std;
char x;
ifstream f("reziston.in");
ofstream g("reziston.out");
int r;
int serie();
int paralel()
{
    int s=0,p=1,k;
    f>>x;
    while(x!=')')
    {
        if(x=='(')
        {
            k=paralel();
            s+=k;
            p*=k;
        }
        else
        if(x=='R')
        {
            k=serie();
            s+=k;
            p*=k;
        }
        if(x==',')
            f>>x;
    }
    f>>x;
    return p/s;
}
int serie()
{
    int s=0,i;
    while(x!=',' && !f.eof() && x!=')')
    {
    if(x=='R')
    {
        i=0;
        f>>x;
        while(x>='0' && x<='9' && !f.eof())
        {
            i=i*10+x-'0';
            f>>x;
        }
        s+=i;
    }
    else
    if(x=='(')
        s+=paralel();
    }
    return s;
}
int main()
{
    f>>x;
    r+=serie();
    g<<r;
}

(R12,R4)R3 vs inversul lui
