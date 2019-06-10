#include <iostream>

using namespace std;

long long n,ans;
char c;

int main()
{
    cin>>n;
    cin>>c;
    ans=(n-1)/4*16;
    if(n%2==1)
    {
        switch(c)
        {
        case 'a':
            ans+=4;
            break;

        case 'b':
            ans+=5;
            break;
        case 'c':
            ans+=6;
            break;
        case 'd':
            ans+=3;
            break;
        case 'e':
            ans+=2;
            break;
        case 'f':
            ans+=1;
            break;
        }
    }
    else
    {
        ans+=7;
        switch(c)
        {
        case 'a':
            ans+=4;
            break;

        case 'b':
            ans+=5;
            break;
        case 'c':
            ans+=6;
            break;
        case 'd':
            ans+=3;
            break;
        case 'e':
            ans+=2;
            break;
        case 'f':
            ans+=1;
            break;
        }
    }
    cout<<ans;
}
