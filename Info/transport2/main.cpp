#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

#define nmax 100010
#define f first
#define s second
#define mp make_pair

vector <pair<int,int> > v[nmax];
int viz[nmax];
int n,m,mn,mx;

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

inline int minim(int a,int b)
{
    if(a<b)
        return a;
    return b;
}

inline int maxim(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

bool bf(int m)
{
    queue <int> q;
    memset(viz, 0, sizeof(viz));

    q.push(1);
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        for(auto it:v[nod])
            if(!viz[it.f] && it.s>=m)
            {
                viz[it.f]=1;
                q.push(it.f);
                if(it.f==n)
                    return 1;
            }
    }
    return 0;
}

int bs(int ls,int ld)
{
    int i=1;
    while((i<<1)<=ld-ls)
        i<<=1;
    for( ; i; i>>=1)
        if(bf(ls+i))
            ls+=i;
    return ls;
}

int main()
{
    freopen("transport2.in","r",stdin);
    freopen("transport2.out","w",stdout);
    citeste(n);
    citeste(m);
    mn=10000;
    int x,y,cst;
    for(int i=1; i<=m; ++i)
    {
        citeste(x);
        citeste(y);
        citeste(cst);
        v[x].push_back(mp(y,cst));
        v[y].push_back(mp(x,cst));
        mn=minim(mn,cst);
        mx=maxim(mx,cst);
    }
    printf("%d",bs(mn,mx));
}
