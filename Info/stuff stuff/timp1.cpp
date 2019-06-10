#include<iostream>
using namespace std;
int m,a,b,h;
int main()
{
    cin>>h>>m>>a>>b;
    m+=b;
    if(m>59)
    {
        m%=60;
        h++;
    }
    h+=a;
    if(h>23)
        h%=24;
    cout<<h<<' '<<m;
}
