#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

ifstream fin("adapost.in");
ofstream fout("adapost.out");

const int inf = 1e9;

#define nmax 805
#define mp make_pair
#define f first
#define s second

vector <int> v[nmax];
vector <int> g[nmax];
pair<int,int> pozs[nmax];
pair<int,int> poza[nmax];
double cst[nmax][nmax];
int c[nmax][nmax];
int f[nmax][nmax];
double d[nmax];
int used[nmax];
int t[nmax];
int r[nmax];
int l[nmax];
int viz[nmax];
long double cost;
int mn,a,b,n;

inline double ab(double x)
{
    if(x<0)
        return -x;
    return x;
}

double dist(pair<int,int> a,pair<int,int> b)
{
    return (double)sqrt(1LL*(a.f-b.f)*(a.f-b.f)+1LL*(a.s-b.s)*(a.s-b.s));
}

bool bf(double mx)
{
    queue <int> h;
    for(int i=1; i<=b; ++i)
        d[i]=inf;
    h.push(a);
    used[a]=1;
    d[a]=0;
    while(!h.empty())
    {
        int nod = h.front();
        h.pop();
        used[nod]=0;
        for(auto it:v[nod])
        {
            if(f[nod][it]<c[nod][it] && d[nod]+cst[nod][it]<d[it] && ab(cst[nod][it])<=mx)
            {
                d[it]=d[nod]+cst[nod][it];
                t[it]=nod;
                if(!used[it])
                {
                    used[it]=1;
                    h.push(it);
                }
            }
        }
    }
    return d[b]!=inf;
}

void flux(int mx)
{
    cost = 0;

    while(bf(mx))
    {
        int flow = inf;
        for(int i=b; i!=a; i=t[i])
            flow=min(flow,c[t[i]][i]-f[t[i]][i]);
        for(int i=b; i!=a; i=t[i])
        {
            f[t[i]][i]+=flow;
            f[i][t[i]]-=flow;
            cost+=cst[t[i]][i];
        }
    }
}

bool pairup(int x,int mx)
{
    if(viz[x])
        return 0;
    viz[x]=1;
    for(auto it:g[x])
        if(!r[it] && ab(cst[x][it+n])<=(double)mx)
        {
            r[it]=x;
            l[x]=it;
            return 1;
        }
    for(auto it:g[x])
        if(ab(cst[x][it+n])<=(double)mx && pairup(r[it],mx))
        {
            r[it]=x;
            l[x]=it;
            return 1;
        }
    return 0;
}

bool cuplaj(int mx)
{
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    int ok=1;
    while(ok)
    {
        ok=0;
        memset(viz, 0, sizeof(viz));
        for(int i=1; i<=n; ++i)
            if(!l[i])
                ok|=pairup(i,mx);
    }
    int ans=0;
    for(int i=1; i<=n; ++i)
        if(l[i])
            ++ans;
    return ans==n;
}

void bs()
{
    mn = 10000000;
    int p=1;
    for( ; p<mn; p<<=1);
    for( ; p; p>>=1)
        while(mn-p>0 && cuplaj(mn-p))
            mn-=p;
}

int main()
{
    fin>>n;
    int i,j;
    for(i=1; i<=n; ++i)
    {
        float a,b;
        fin>>a>>b;
        pozs[i]=mp(a*10000,b*10000);
    }
    for(i=1; i<=n; ++i)
    {
        float a,b;
        fin>>a>>b;
        poza[i]=mp(a*10000,b*10000);
    }
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
        {
            g[i].push_back(j);

            c[i][j+n]=1;
            cst[i][j+n]=dist(pozs[i],poza[j]);
            cst[j+n][i]=-cst[i][j+n];
            v[i].push_back(j+n);
            v[j+n].push_back(i);
        }
    a = 0;
    b = 2*n+1;
    for(i=1; i<=n; ++i)
    {
        c[a][i]=1;
        v[a].push_back(i);
    }
    for(i=1; i<=n; ++i)
    {
        c[n+i][b]=1;
        v[n+i].push_back(b);
    }
    bs();
    flux(mn);
    fout<<setprecision(10)<<fixed<<(double)mn/10000<<' '<<(double)cost/10000;
}
