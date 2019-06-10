#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("reuniune.in");
ofstream fout("reuniune.out");

struct drept
{
    long long sx,sy,dx,dy;
};

drept intersectie(drept a,drept b)
{
    long long q,w,e,r;
    q=max(a.sx,b.sx);
    w=max(a.sy,b.sy);
    e=min(a.dx,b.dx);
    r=min(a.dy,b.dy);
    if(q>e || w>r)
        q=w=e=r=0;
    drept p;
    p.sx=q;
    p.sy=w;
    p.dx=e;
    p.dy=r;
    return p;
}

long long s(drept a)
{
    return (a.dx-a.sx) * (a.dy-a.sy);
}

long long p(drept a)
{
    return (a.dy-a.sy + a.dx - a.sx )*2;
}

drept a,b,c;

int main()
{
    fin>>a.sx>>a.sy>>a.dx>>a.dy;
    fin>>b.sx>>b.sy>>b.dx>>b.dy;
    fin>>c.sx>>c.sy>>c.dx>>c.dy;
    fout<<s(a) + s(b) + s(c) - s(intersectie(a,b)) - s(intersectie(b,c)) - s(intersectie(a,c)) + s(intersectie(a,intersectie(b,c)))<<' ';
    fout<<p(a) + p(b) + p(c) - p(intersectie(a,b)) - p(intersectie(b,c)) - p(intersectie(a,c)) + p(intersectie(a,intersectie(b,c)))<<' ';
}
