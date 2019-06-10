#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

ifstream fin("seg.in");
ofstream fout("seg.out");

inline int p(int x)
{
    return (1<<x);
}

#define f first
#define s second
#define mp make_pair
#define nmax 17

const int inf = 1000000000;

double cost[nmax*2][nmax*2];
double d[(1<<(nmax-1))][nmax][2];
pair<double,double> v[nmax*2];
int t,i,n,j,k,z;
double ans,x1,x2,y3,y2;

inline double dist(pair<double,double> a, pair<double,double> b)
{
    return (double)sqrt((a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s));
}

int main()
{
    fin>>t;
    for( ; t--; )
    {
        fin>>n;
        for(i=0; i<n; ++i)
        {
            fin>>x1>>y3>>x2>>y2;
            v[2*i]=mp(x1,y3);
            v[2*i+1]=mp(x2,y2);
        }

        for(i=0; i<2*n; ++i)
            for(j=0; j<2*n; ++j)
                cost[i][j]=inf;

        for(i=0; i<n; ++i)
            for(j=0; j<n; ++j)
            if(i!=j)
            {
                cost[(i<<1)][(j<<1)]=min(cost[2*i][2*j],dist(v[2*i],v[2*j]));
                cost[(i<<1)+1][(j<<1)]=min(cost[2*i+1][2*j],dist(v[2*i+1],v[2*j]));
                cost[(i<<1)][(j<<1)+1]=min(cost[2*i][2*j+1],dist(v[2*i],v[2*j+1]));
                cost[(i<<1)+1][(j<<1)+1]=min(cost[2*i+1][2*j+1],dist(v[2*i+1],v[2*j+1]));
            }
        int x = p(n-1);

        for(j=0; j<=x; ++j)
            for(i=0; i<n; ++i)
                d[j][i][0]=d[j][i][1]=inf;

        d[0][0][0]=0;
        x=p(n);
        for(j=1; j<x; j+=2)
            for(i=0; i<n; ++i)
                if(j & p(i))
                    for(k=0; k<n; ++k)
                        if(j & p(k))
                        {
                            z=j/2;
                            d[z][i][0]=min(d[z][i][0],d[(j^p(i))/2][k][0] + cost[(k<<1)+1][(i<<1)]);
                            d[z][i][0]=min(d[z][i][0],d[(j^p(i))/2][k][1] + cost[(k<<1)][(i<<1)]);

                            d[z][i][1]=min(d[z][i][1],d[(j^p(i))/2][k][0] + cost[(k<<1)+1][(i<<1)+1]);
                            d[z][i][1]=min(d[z][i][1],d[(j^p(i))/2][k][1] + cost[(k<<1)][(i<<1)+1]);
                        }
        ans=inf;
        x=p(n);
        for(i=0; i<n; ++i)
        {
            ans=min(ans,d[(x-1)/2][i][0] + cost[(i<<1)+1][0]);
            ans=min(ans,d[(x-1)/2][i][1] + cost[(i<<1)][0]);
        }
        fout<<setprecision(6)<<fixed<<ans<<'\n';
    }
}
