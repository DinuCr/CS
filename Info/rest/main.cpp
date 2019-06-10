#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("rest.in");
ofstream fout("rest.out");

#define nmax 250005

short v[nmax*2];
int l[nmax*2];
short w[nmax];
int n,m,i;
short p;
int p2;

inline short mod(int x)
{
    if(x>=p)
        return x%p;
    return x;
}

inline void build()
{
    for(int i=n-1; i>0; --i)
    {
        l[i]=l[i<<1]+l[i<<1|1];
        v[i]=mod(1*w[l[i<<1|1]]*v[i<<1]+v[i<<1|1]);
    }
}

inline void update(int a,int b)
{
    v[a+=n]=b;
    for(a>>=1; a>0; a>>=1)
        v[a]=mod(1*w[l[a<<1|1]]*v[a<<1]+v[a<<1|1]);
}

inline short query(int a,int b)
{
    short ans = 0;
    int x=b-a,y=0;
    for(a+=n,b+=n; a<b; a>>=1,b>>=1)
    {
        if(a&1)
        {
            x-=l[a];
            ans = mod(ans+1*v[a]*w[x]);
            ++a;
        }
        if(b&1)
        {
            --b;
            ans = mod(ans+1*v[b]*w[y]);
            y+=l[b];
        }
    }
    return ans;
}

#define DIM 10000
char buff[DIM];
int poz=0;

inline void citeste(int &numar)
{
     numar = 0;
     //cat timp caracterul din buffer nu e cifra ignor
     while (buff[poz] < '0' || buff[poz] > '9')
          //daca am "golit" bufferul atunci il umplu
          if (++poz == DIM)
               fin.read(buff,DIM),poz=0;
     //cat timp dau de o cifra recalculez numarul
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fin.read(buff,DIM),poz=0;
     }
}

int main()
{
    int b2;
    short b;
    citeste(n);
    citeste(b2);
    citeste(p2);
    b = b2;
    p = p2;

    for(i=0; i<n; ++i)
    {
        citeste(b2);
        v[i+n]=b2;
        l[i+n]=1;
    }
    w[0]=1;
    for(i=1; i<=n; ++i)
        w[i]=mod(1*w[i-1]*b);
    build();
    citeste(m);
    int ok,x,y;
    while(m--)
    {
        citeste(ok);
        citeste(x);
        citeste(y);
        if(ok==1)
            update(x-1,y);
        else
            fout<<query(x-1,y)<<'\n';
    }
}
