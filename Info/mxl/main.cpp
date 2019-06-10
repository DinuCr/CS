#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
typedef struct cas
{
    int x,y;
};
typedef struct cell
{
    long long sm,nr;
    cas t[65];
};
cell v[45][45];
int i,j,n,k,p,a,b,x,y;
long long rec(int i,int j)
{
    for(int p=1;p<=v[i][j].nr;p++)
    if(v[i][j].t[p].x+v[i][j].t[p].y!=0)
    {
        v[i][j].sm+=rec(v[i][j].t[p].x,v[i][j].t[p].y);
        v[i][j].t[p].x=0;
        v[i][j].t[p].y=0;
    }
    return v[i][j].sm;
}
ifstream f("mxl.in");
ofstream g("mxl.out");
char s[300];
int main()
{
    f>>n>>k;
    for(int z=1; z<=k; z++)
    {
        f>>a>>b;
        f.getline(s,270);
        p=strlen(s);
        for(int i=1; i<p; i++)
        {
            x=0;
            while(s[i]<='9' && s[i]>='0')
            {
                x=x*10+s[i]-'0';
                i++;
            }
            if(x!=0)
            {
                if(s[i]=='+' || i==p)
                    v[a][b].sm+=x;
                else if(s[i]==':')
                {
                    i++;
                    y=0;
                    while(s[i]<='9' && s[i]>='0')
                        y=y*10+s[i]-'0',i++;
                    v[a][b].nr++;
                    v[a][b].t[v[a][b].nr].x=x;
                    v[a][b].t[v[a][b].nr].y=y;
                }
            }
        }
    }
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            if(v[i][j].nr!=0)
                v[i][j].sm=rec(i,j);
        }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            g<<v[i][j].sm<<' ';
        g<<'\n';
    }
}
