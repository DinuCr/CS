#include <iostream>
#include <cstring>
using namespace std;

const long long mod = 1000000007    ;
long long v[100100];

long long x,n,i,a,k;
char s[100100];

int main()
{
    cin.getline(s,100100);
    n=strlen(s);
    for(i=0; i<n; ++i)
    {
        if(s[i]<='9' && s[i]>='0')
            x=s[i]-'0';
        else
        if(s[i]>='A' && s[i]<='Z')
            x=10+s[i]-'A';
        else
        if(s[i]>='a' && s[i]<='z')
            x=36+s[i]-'a';
        else
        if(s[i]=='-')
            x=62;
        else
        if(s[i]=='_')
            x=63;
        v[i]=x;
    }
    long long nr=1;
    for(i=0; i<n; ++i)
    {
        for(k=0; k<6; ++k)
            if(((1<<k)&v[i])==0)
            {
                nr*=3;
                ++a;
                if(a>15)
                {
                    a=0;
                    nr%=mod;
                }
            }
    }
    cout<<nr%mod;
}
