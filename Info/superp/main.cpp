#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("superp.in");
ofstream fout("superp.out");

#define nmax 1001000


long long po[15];
int n;
int boo[nmax];
int prim[nmax];
int cifre[11];
long long ans,nr;
int i,j;

void bkt(int pas)
{
    for(int i=0; i<=9; ++i)
        if(cifre[i])
        {
            --cifre[i];

            nr=nr*10+i;

            if(nr<=1000000)
            {
                if(boo[nr])
                {
                    ++cifre[i];
                    nr/=10;
                    continue;
                }
            }
            else
            {
                int ok=0,z=sqrt(nr);
                for(int j=1; prim[j]<=z; ++j)
                    if(nr%prim[j]==0)
                    {
                        ok=1;
                        break;
                    }
                if(ok)
                {
                    ++cifre[i];
                    nr/=10;
                    continue;
                }
            }
            ans=max(ans,nr);
            bkt(pas+1);
            ++cifre[i];
            nr/=10;
        }
}

int main()
{
    cin>>n;

    for(i=2; i<=1000; ++i)
        if(!boo[i])
            for(j=i*i; j<=1000001; j+=i)
                boo[j]=1;

    boo[0]=boo[1]=1;
    int k = 0 ;
    for(i=2; i<=1000001; ++i)
        if(!boo[i])
            prim[++k]=i;
    prim[++k]=10001000;

    while(n--)
    {
        long long x;
        cin>>x;
        for(i=0; i<10; ++i)
            cifre[i]=0;
        ans=0;
        while(x)
        {
            ++cifre[x%10];
            x/=10;
        }
        bkt(1);
        cout<<ans<<'\n';
    }
}
