#include <cstdio>
#include <vector>

using namespace std;

int d[(1<<17)+10];
int p[20];
int n,m;

const int mx = (1e9) *2;

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
    freopen("promotie.in","r",stdin);
    freopen("promotie.out","w",stdout);
    int i,nr,cst,a;
    citeste(m);
    citeste(n);
    p[0]=1;
    for(i=1; i<=m; ++i)
        p[i]=p[i-1]<<1;
    for(i=0; i<p[m]; ++i)
        d[i]=mx;
    vector <int> poz;
    d[0]=0;
    poz.push_back(0);
    for(i=1; i<=n; ++i)
    {
        citeste(nr);
        citeste(cst);
        vector <int> curr;
        int x = 0;
        while(nr--)
        {
            citeste(a);
            x+=p[a-1];
        }
        if(d[x]>cst)
        {
            for(auto it:poz)
            {
                if(d[it|x]==mx)
                    curr.push_back(it|x);
                if(it==x)
                    d[it]=min(d[it],cst);
                else
                    d[it|x]=min(d[it|x],d[it]+cst);
            }
            for(auto it:curr)
                poz.push_back(it);
        }
    }
    printf("%d",d[p[m]-1]);
}
