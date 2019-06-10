#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define nmax 1000100

char s[nmax];
int v[nmax],n,i,nr,f[10];

void ran(int n)
{

}

bool divisible(int n)
{
    int s=0,x=0,ok=1,i;
    for(i=n-1; i>=0; i-=3)
    {
        if(i>1)
        x=v[i]+v[i-1]*10+v[i-2]*100;
        else
        if(i>0)
        x=v[i]+v[i-1]*10;
        else
        if(i==0)
        x=v[i];

        if(ok)
        {
            s+=x;
            ok=0;
        }
        else
        {
            s-=x;
            ok=1;
        }
    }
    if(s-s/7*7==0)
        return 1;
    return 0;
}

int main()
{
    cin>>s;
    int n=strlen(s);
    for(i=0; i<n; ++i)
        v[i]=s[i]-'0';

    for(i=0; i<n; ++i)
        f[v[i]]++;

    n=0;

    for(i=1; i<=9; ++i)
        if(i!=1 && i!=6 && i!=8 && i!=9)
        {
            while(f[i])
            {
                cout<<i;
                v[n++]=i;
                --f[i];
            }
        }
        else
        {
            while(f[i]>1)
            {
                cout<<i;
                v[n++]=i;
                --f[i];
            }
        }
    v[n]=1;
    v[n+1]=6;
    v[n+2]=8;
    v[n+3]=9;
    n+=4;
    nr=0;
    while(!divisible(n))
    {
        next_permutation(v+n-4,v+n);
        ++nr;
        if(nr>20)
        {
            cout<<0;
            return 0;
        }
    }
    cout<<v[n-4]<<v[n-3]<<v[n-2]<<v[n-1];
    while(f[0])
    {
        cout<<0;
        f[0]--;
    }
}
