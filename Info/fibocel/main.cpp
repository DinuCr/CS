#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("fibocel.in");
ofstream fout("fibocel.out");

long long a,b,i;
long long c[100][100];
int fib[10] = {1,2,3,5,8,13,21,34,55};
long long putere[100];

long long f(long long x)
{
    long long ans = 0;
    int nr = 0;
    int i,j;
    int maxim=0;
    for(i=55; i>=0; --i)
        if(x&(putere[i]))
        {
            for(j=0; fib[j]-nr<=i; ++j)
                if(fib[j]-nr>-1)
                    ans+=c[i][fib[j]-nr];
            ++nr;
        }
    if(nr==1 || nr==2 || nr==3 || nr==5 || nr==8 || nr==13 || nr==21 || nr==34 || nr==55)
            ++ans;
    return ans;
}

void comb()
{
    int i,j;
    int n = 55;
    for(i=0; i<=n; ++i)
        c[i][0]=c[i][i]=1;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
            if(i!=j)
                c[i][j]=c[i-1][j]+c[i-1][j-1];
}

int main()
{
    putere[0]=1;
    for(i=1; i<=60; ++i)
        putere[i]=2*putere[i-1];
    int q;
    fin>>q;
    comb();
    cout<<f(21);
    while(q--)
    {
        fin>>a>>b;
        fout<<f(b)-f(a-1)<<'\n';
    }
}
