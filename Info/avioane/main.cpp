#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdio>

using namespace std;

int n;
int v[100100];
int d[100100];
int i,j;

#define DIM 10000
char buff[DIM];
int poz=0;

void citeste(int &numar)
{
     numar = 0;
     //cat timp caracterul din buffer nu e cifra ignor
     while (buff[poz] < '0' || buff[poz] > '9')
          //daca am "golit" bufferul atunci il umplu
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     //cat timp dau de o cifra recalculez numarul
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fread(buff,1,DIM,stdin),poz=0;
     }
}

void solve(int l,int r)
{
    if(l>r)
        return ;
    int m = (l+r)>>1;
    long long best = 0;
    int lim = min(m,d[r+1]);
    for(int i=d[l-1]; i<=lim; ++i)
    {
        long long curr = 1LL*v[i]*(m-i);
        if(curr>best)
        {
            best=curr;
            d[m]=i;
        }
    }
    solve(l,m-1);
    solve(m+1,r);
}

int main()
{

    freopen("avioane.in","r",stdin);
    freopen("avioane.out","w",stdout);

    citeste(n);
    for(i=1; i<=n; ++i)
        citeste(v[i]);
    sort(v+1,v+n+1);
    d[n+1]=n;
    solve(1,n);
    long long ans = 0;
    for(i=1; i<=n; ++i)
        ans=max(ans,1LL*v[i]*(n-i+1)+1LL*v[d[i]]*(i-d[i]));
    printf("%lld",ans);
}
