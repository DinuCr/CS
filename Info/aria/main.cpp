#include <cstdio>
#include <cmath>

using namespace std;

FILE *f=fopen("aria.in","r");
FILE *g=fopen("aria.out","w");

#define fs fscanf
#define fp fprintf

struct nod
{
    double x,y;
};
nod v[100010];

inline double d(nod a,nod b)
{
    return (a.x * b.y - a.y * b.x)/2;
}
int i,n;
double s;

int main()
{
    fs(f,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fs(f,"%lf",&v[i].x);
        fs(f,"%lf",&v[i].y);
    }
    v[n+1]=v[1];
    for(i=1;i<=n;i++)
        s+=d(v[i],v[i+1]);
    fp(g,"%lf",abs(s));
}
