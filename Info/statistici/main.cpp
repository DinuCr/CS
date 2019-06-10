#include<iostream>
#include<fstream>
using namespace std;
ifstream f("statistici.in");
typedef struct coord
{
    int x,y;
};
coord v[100];
int mx,my,x,y,ok,nr,k,i,n,m;
int verif(int x,int y,int x1,int y1,int x2,int y2)
{
    int f1,f2;
    f1=x*(y2-y1)-y*(x2-x1)-x1*y2+y1*x2;
    f2=mx*(y2-y1)-my*(x2-x1)-x1*y2+y1*x2;
    if(f1*f2<0)
        return 0;
    return 1;
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>v[i].x>>v[i].y;
        mx+=v[i].x;
        my+=v[i].y;
    }
    mx/=n;
    my/=n;
    f>>m;
    n++;
    v[n]=v[1];
    for(k=1;k<=m;k++)
    {
        f>>x>>y;
        ok=1;
        for(i=1;i<n;i++)
            if(!verif(x,y,v[i].x,v[i].y,v[i+1].x,v[i+1].y))
            {
                ok=0;
                break;
            }
        nr+=ok;
    }
    cout<<nr;
}
