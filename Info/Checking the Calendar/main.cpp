#include <iostream>

using namespace std;

char a[30],b[30],a1,b1,i;

int main()
{
    cin>>a>>b;
    switch(a[2])
    {
    case 'n':
        if(a[0]=='m')
            a1=1;
        else
            a1=7;
        break;
    case 'e':
        a1=2;
        break;
    case 'd':
        a1=3;
        break;
    case 'u':
        a1=4;
        break;
    case 'i':
        a1=5;
        break;
    case 't':
        a1=6;
        break;
    }

    switch(b[2])
    {
    case 'n':
        if(b[0]=='m')
            b1=1;
        else
        b1=7;
        break;
    case 'e':
        b1=2;
        break;
    case 'd':
        b1=3;
        break;
    case 'u':
        b1=4;
        break;
    case 'i':
        b1=5;
        break;
    case 't':
        b1=6;
        break;
    }
    int ok=0;
    int v[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=0; i<11; ++i)
        if(((a1+v[i])%7==0 && b1==7 ) || (a1+v[i])%7==b1 )
            ok=1;
    if(ok)
        cout<<"YES";
    else
        cout<<"NO";

}
