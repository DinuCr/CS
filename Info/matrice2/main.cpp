#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream fin("matrice2.in");
ofstream fout("matrice2.out");

#define mp make_pair
#define f first
#define s second

struct query
{
    int x1,x2,y1,y2,i;
};

int w[305][305];
int t[900005];
query q[20010];
pair<int,pair<int,int> > v[900005];
int ans[20010];
int n,qr;
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
int i,j,mx;

int root(int x)
{
    if(!t[x])
        return x;
    t[x]=root(t[x]);
    return t[x];
}

inline int convert(int x,int y)
{
    return (x-1)*n+y;
}

bool cmp(query a,query b)
{
    return a.i<b.i;
}

bool cmp1(query a,query b)
{
    return ans[a.i]>ans[b.i];
}

void bs()
{
    int step;
    for(step=1; step<mx; step<<=1);

    for( ; step; step>>=1)
    {
        sort(q+1,q+qr+1,cmp1);
        memset(w,0,sizeof(w));
        memset(t,0,sizeof(t));
        int last = n*n;
        for(int i=1; i<=qr; ++i)
        {
            int a,b;
            while(v[last].f>=ans[q[i].i]+step)
            {
                a = v[last].s.f;
                b = v[last].s.s;
                w[a][b]=1;
                for(int k=0; k<4; ++k)
                    if(w[a+dx[k]][b+dy[k]])
                    {
                        if(root(convert(a+dx[k],b+dy[k]))!=root(convert(a,b)))
                            t[root(convert(a,b))]=root(convert(a+dx[k],b+dy[k]));
                    }
                --last;
            }
            if(root(convert(q[i].x1,q[i].y1))==root(convert(q[i].x2,q[i].y2)))
                ans[q[i].i]+=step;
        }
    }
}

int main()
{
    fin>>n>>qr;
    int k=0;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
        {
            int x;
            fin>>x;
            v[++k]=mp(x,mp(i,j));
            mx=max(mx,x);
        }
    sort(v+1,v+n*n+1);
    for(i=1; i<=qr; ++i)
    {
        fin>>q[i].x1>>q[i].y1>>q[i].x2>>q[i].y2;
        q[i].i=i;
    }
    bs();
    sort(q+1,q+qr+1,cmp);
    for(i=1; i<=qr; ++i)
        fout<<ans[i]<<'\n';
}
