#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

ifstream fin("sushi2.in");
ofstream fout("sushi2.out");

#define nmax 100010
#define mp make_pair
#define f first
#define s second

map <pair<int,int> ,int> h;
vector <int> v[nmax];
int e[nmax<<2];
int last[nmax];
int ans[nmax];
int nxt[nmax<<2];
pair<int,int> aint[nmax<<3];
int n,m,k;

void df(int x,int t)
{
    e[k++]=x;
    for(auto it:v[x])
        if(t!=it)
        {
            df(it,x);
            e[k++]=x;
        }
}

void build(int n)
{
    for(int i=n-1; i>0; --i)
    {
        if(aint[i<<1].s && aint[i<<1|1].s)
        {
            if(aint[i<<1].f+aint[i<<1|1].s-aint[i<<1].s<aint[i<<1|1].f)
                aint[i]=aint[i<<1|1];
            else
                aint[i]=aint[i<<1];
        }
        else
        if(aint[i<<1].s)
        {
            aint[i]=aint[i<<1];
        }
        else
        if(aint[i<<1|1].s)
        {
            aint[i]=aint[i<<1|1];
        }
    }
}

int query(int a,int b,int poz)
{
    int rez = 0;
    for( ; a<b; a>>=1,b>>=1)
    {
        if(a&1)
        {
            if(aint[a].s)
                rez = max(rez,aint[a].f+poz-aint[a].s);
            ++a;
        }
        if(b&1)
        {
            --b;
            if(aint[b].s)
                rez = max(rez,aint[b].f+poz-aint[b].s);
        }
    }
    return rez;
}

int main()
{
    int i;
    fin>>n>>m;
    for(i=1; i<=n; ++i)
    {
        int x,y;
        fin>>x;
        for(int j=1; j<=x; ++j)
        {
            fin>>y;
            v[i].push_back(y);
        }
    }
    df(1,0);
    --k;
    int k2 = k*2;
    for(i=k; i<k2; ++i)
        e[i]=e[i-k];
    for(i=k2-1; i>=0; --i)
    {
       if(last[e[i]]!=0)
            nxt[i]=last[e[i]];
       last[e[i]]=i;
    }
    for(i=0; i<k; ++i)
        h[mp(e[i],e[i+1])]=i;
    int t,x,y;
    for(i=1; i<=m; ++i)
    {
        fin>>x>>y>>t;
        y = v[x][y-1];
        int poz = h[mp(x,y)];
        aint[poz+k2]=mp(max(aint[poz+k2].f,t),poz+1);
        aint[poz+k2+k]=mp(max(aint[poz+k2].f,t),poz+k+1);
    }
    build(k2);
    for(i=0; i<k2; ++i)
    {
        if(nxt[i])
            ans[e[i]]=max(ans[e[i]],query(i+k2+1,nxt[i]+1+k2,nxt[i]+1));
    }
    for(i=1; i<=n; ++i)
        fout<<ans[i]<<' ';
}
