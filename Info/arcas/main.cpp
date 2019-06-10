#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("arcas.in");
ofstream fout("arcas.out");

#define nmax 200010
#define mp make_pair
#define f first
#define s second
#define zeros(x) (x&(x^(x-1)))

struct target
{
    int x,y1,y2;
};
struct ray
{
    int x,y,r;
};

int aib[nmax*2];
pair<int,pair<int,int> > event[nmax*3];
target t[nmax];
ray v[nmax];
int d[nmax];
int n,m,i,k;

bool cmp(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b)
{
    if(a.f!=b.f)
        return a.f<b.f;
    return a.s.f<b.s.f;
}

void update(int x,int val)
{
    for( ; x<nmax*2; x+=zeros(x))
        aib[x]+=val;
}

int compute(int x)
{
    int ans = 0;
    for( ; x>0; x-=zeros(x))
        ans+=aib[x];
    return ans;
}

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; ++i)
    {
        fin>>t[i].x>>t[i].y1>>t[i].y2;
        event[++k]=mp(t[i].x-t[i].y2+nmax,mp(1,i));
        event[++k]=mp(t[i].x-t[i].y1+nmax,mp(3,i));
    }
    for(i=1; i<=m; ++i)
    {
        fin>>v[i].x>>v[i].y>>v[i].r;
        event[++k]=mp(v[i].x-v[i].y+nmax,mp(2,i));
    }
    sort(event+1,event+k+1,cmp);
    for(i=1; i<=k; ++i)
    {
        switch(event[i].s.f)
        {
        case 1:
            update(t[event[i].s.s].x,1);
            break;
        case 3:
            update(t[event[i].s.s].x,-1);
            break;
        case 2:
            d[event[i].s.s]=compute(v[event[i].s.s].x+v[event[i].s.s].r) - compute(v[event[i].s.s].x-1);
            break;
        }
    }
    for(i=1; i<=m; ++i)
        fout<<d[i]<<'\n';
}
