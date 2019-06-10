#include <iostream>
#include <cstring>
using namespace std;
char s[22];
int n,nr,x;
int main()
{
    cin>>x;
    cin.getline(s,20);
    if(strcmp(s," of week")==0)
    {
        if(x<=7 && x>=5)
            nr++;
        n=x+3;
        while(n<=366)
        {
            nr++;
            n+=7;
        }
        cout<<nr;
    }
    else
    {
        if(x<=29)
            cout<<12;
        else
        if(x==30)
            cout<<11;
        else
            cout<<7;
    }
}
