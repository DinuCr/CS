#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>

using namespace std;

ofstream fout("ruksak.out");

#define nmax 300010
#define f first
#define s second
#define mp make_pair

vector <int> o[3010];
pair <int,int> v[nmax];
int d[3010],n,g,i,j,k;

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

int main()
{
    freopen("ruksak.in","r",stdin);
    citeste(n);
    citeste(g);
    int sum = 0;
    for(i=1; i<=n; ++i)
    {
        int a,b;
        citeste(a);
        citeste(b);
        o[a].push_back(b);
        if(a==0)
            sum+=b;
    }
    int cnt;
    for(i=1; i<=g; ++i)
        if(o[i].size())
        {
            sort(o[i].begin(),o[i].end());
            cnt=(i==0)?1e6:g/i;
            for(j=o[i].size()-1; j>=0 && cnt; --j,--cnt)
                v[++k]=mp(i,o[i][j]);
        }
    for(i=1; i<=k; ++i)
    {
        for(j=g-v[i].f; j>=0; --j)
            if(d[j])
                d[j+v[i].f]=max(d[j+v[i].f],d[j]+v[i].s);
        d[v[i].f]=max(d[v[i].f],v[i].s);
    }
    int ans = 0;
    for(i=1; i<=g; ++i)
        ans=max(ans,d[i]);
    fout<<ans+sum;
}
