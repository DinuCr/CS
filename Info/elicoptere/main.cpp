#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream fin("elicoptere.in");
ofstream fout("elicoptere.out");

#define nmax 105
#define pb push_back
#define mp make_pair
#define f first
#define s second

struct tri
{
    int ax,ay,bx,by,cx,cy;
};

tri v[nmax];
vector <pair<int,double> > g[nmax];
vector <pair<double,pair<int,int> > > edge;
int viz[nmax],ans1,ans2,nr;
int p,n,k,i,j;
int t[nmax];

double xx(int y,int xa,int ya,int xb,int yb)
{
    if(yb!=ya)
        return ((double)((y-ya)*(xb-xa))/(yb-ya) + xa);
    return -1;
}

double yy(int x,int xa,int ya,int xb,int yb)
{
    if(xb!=xa)
        return ((double)((x-xa)*(yb-ya))/(xb-xa) + ya);
    return -1;
}

double calc(int x,int y,int ax,int ay,int bx,int by)
{
    double ans = 1e9;
    if(min(ax,bx)<=x && x<=max(bx,ax))
        if(yy(x,ax,ay,bx,by)!=-1)
            ans = min(ans,abs(y-yy(x,ax,ay,bx,by)));
    if(min(ay,by)<=y && y<=max(by,ay))
        if(xx(y,ax,ay,bx,by)!=-1)
            ans = min(ans,abs(x-xx(y,ax,ay,bx,by)));
    return ans;
}

double dist(tri a,tri b)
{
    double ans = 1e9;
    ans = min(ans,calc(a.ax,a.ay,b.ax,b.ay,b.bx,b.by));
    ans = min(ans,calc(a.ax,a.ay,b.cx,b.cy,b.bx,b.by));
    ans = min(ans,calc(a.ax,a.ay,b.ax,b.ay,b.cx,b.cy));

    ans = min(ans,calc(a.bx,a.by,b.ax,b.ay,b.bx,b.by));
    ans = min(ans,calc(a.bx,a.by,b.cx,b.cy,b.bx,b.by));
    ans = min(ans,calc(a.bx,a.by,b.ax,b.ay,b.cx,b.cy));


    ans = min(ans,calc(a.cx,a.cy,b.ax,b.ay,b.bx,b.by));
    ans = min(ans,calc(a.cx,a.cy,b.cx,b.cy,b.bx,b.by));
    ans = min(ans,calc(a.cx,a.cy,b.ax,b.ay,b.cx,b.cy));

    ans = min(ans,calc(b.ax,b.ay,a.ax,a.ay,a.bx,a.by));
    ans = min(ans,calc(b.ax,b.ay,a.cx,a.cy,a.bx,a.by));
    ans = min(ans,calc(b.ax,b.ay,a.ax,a.ay,a.cx,a.cy));

    ans = min(ans,calc(b.bx,b.by,a.ax,a.ay,a.bx,a.by));
    ans = min(ans,calc(b.bx,b.by,a.cx,a.cy,a.bx,a.by));
    ans = min(ans,calc(b.bx,b.by,a.ax,a.ay,a.cx,a.cy));


    ans = min(ans,calc(b.cx,b.cy,a.ax,a.ay,a.bx,a.by));
    ans = min(ans,calc(b.cx,b.cy,a.cx,a.cy,a.bx,a.by));
    ans = min(ans,calc(b.cx,b.cy,a.ax,a.ay,a.cx,a.cy));

    return ans;
}

void df(int x)
{
    viz[x]=1;
    ++nr;
    for(auto it:g[x])
    {
        if(!viz[it.f])
        {
            df(it.f);
        }
    }
}

int root(int x)
{
    if(!t[x])
        return x;
    t[x]=root(t[x]);
    return t[x];
}

void apm()
{
    double ans = 0;
    sort(edge.begin(),edge.end());
    for(auto it:edge)
    {
        if(root(it.s.f)==root(it.s.s))
            continue;
        ans +=it.f;
        t[root(it.s.f)]=root(it.s.s);
    }
    fout<<setprecision(6)<<fixed<<ans;
}

int main()
{
    fin>>p;
    fin>>n>>k;
    for(i=1; i<=n; ++i)
        fin>>v[i].ax>>v[i].ay>>v[i].bx>>v[i].by>>v[i].cx>>v[i].cy;
    for(i=1; i<=n; ++i)
        for(j=i+1; j<=n; ++j)
        {
            double x = dist(v[i],v[j]);
            if(x<=(double)k)
            {
                g[i].pb(mp(j,x));
                g[j].pb(mp(i,x));
                edge.push_back(mp(x,mp(i,j)));
            }
        }
    for(i=1; i<=n; ++i)
        if(!viz[i])
            {
                nr=0;
                df(i);
                ++ans1;
                ans2 += (nr-1)*nr/2;
            }
    switch(p)
    {
    case 1:
        fout<<n-ans1;
        break;
    case 2:
        fout<<ans2;
        break;
    case 3:
        apm();
        break;
    }
}
