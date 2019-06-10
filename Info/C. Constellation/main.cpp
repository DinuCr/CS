#include <iostream>
#include <cmath>
using namespace std;
typedef struct coord
{
    int x,y;
};
coord v[100100],w[100100];
int n,i;
void qsort(int inf, int sup)
{
    int x, i, j, t;
    i = inf;
    j = sup;
    x = v[(i + j) / 2].x;
    do
    {
        while ( (i < sup) &&(v[i].x < x) ) i++;
        while ( (j > inf) &&(v[j].x > x) ) j--;
        if ( i<= j )
        {
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
    while ( i <= j );
    if ( inf < j ) qsort(inf, j);
    if ( i < sup ) qsort(i, sup);
}
int s(coord a,coord b,coord c)
{
    return abs(a.x*b.y+a.y*c.x+b.x*c.y-b.x*a.y-a.x*c.y-c.x*b.y);
}
bool cond(coord a,coord b,coord c)
{
    for(int i=3;i<=n && v[i].x<=c.x;i++)
    if(v[i].x!=c.x && v[i].y!=c.y)
    {
        if(s(a,b,c)==s(a,b,v[i])+s(a,c,v[i])+s(b,c,v[i]))
            return 0;
    }
    return 1;
}
coord p1,p2,p3;
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>v[i].x>>v[i].y;
        w[i]=v[i];
    }
    qsort(1,n);
    p1=v[1];
    p2=v[2];
    i=3;
    p3=v[i];
    while(s(p1,p2,p3)==0 || !cond(p1,p2,p3))
    {
        i++;
        p3=v[i];
    }
    for(i=1;i<=n;i++)
        if(w[i].x==p1.x && w[i].y==p1.y)
        {
            cout<<i<<' ';
            break;
        }
    for(i=1;i<=n;i++)
        if(w[i].x==p2.x && w[i].y==p2.y)
        {
            cout<<i<<' ';
            break;
        }
    for(i=1;i<=n;i++)
        if(w[i].x==p3.x && w[i].y==p3.y)
        {
            cout<<i;
            break;
        }
}
