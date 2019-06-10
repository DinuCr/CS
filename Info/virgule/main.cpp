#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("virgule.in");
ofstream fout("virgule.out");

char v[100];
long long  poz[100];
long long num[100];
long long mn=1000000000000000000;
long long  ans[100],n,i,m;
long long ansnr[100];

inline bool verif(long long  nr)
{
    long long  i=1;
    while(ansnr[i]==num[i] && i<nr)
        ++i;
    if(num[i]>ansnr[i])
        return 1;
    return 0;
}

void bkt(long long x,long long  k,long long  ord)
{
    if(k==n)
    {
        if(x<mn)
        {
            mn=x;
            for(i=1; i<ord; ++i)
            {
                ans[i]=poz[i];
                ansnr[i]=num[i];
            }
            m=ord;
        }
        else if(x==mn)
            if(verif(ord))
            {
                mn=x;
                for(i=1; i<ord; ++i)
                {
                    ans[i]=poz[i];
                    ansnr[i]=num[i];
                }
                m=ord;
            }

    }
    long long  i;
    long long nr=0;
    for(i=0; i<17 && i+k<n; ++i)
    {
        nr=nr*10+v[k+i]-'0';
        if(nr<=mn)
        {
            if(nr>x)
            {
                num[ord]=nr;
                poz[ord]=i+k;
                bkt(nr,i+k+1,ord+1);
            }
        }
        else
            return;
    }
}

int main()
{
    fin>>v;
    n=strlen(v);
    bkt(0,0,1);
    ans[m]=n;
    ans[0]=-1;
    for(long long  j=0; j<=m; ++j)
    {
        for(i=ans[j]+1; i<=ans[j+1]; ++i)
            fout<<v[i];
        if(i<n)
            fout<<',';
    }

}

100000000000000000
100000000000000000
