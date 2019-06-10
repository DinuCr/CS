#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

ifstream f("concurs.in");
ofstream g("concurs.out");

#define nmax 33010

vector <int> v[nmax];

bool boss[nmax];

int e[nmax*2];
int lev[nmax*2];
int rmq[20][nmax*2];
int first[nmax];
int puncte[nmax];
int p[25];

int n,m,k,i,j,xf,yf,x,y,a,b,r,l,q,mx;

void euler(int x,int y)
{
    ++n;
    e[n]=x;
    lev[n]=y;
    if(first[x]==0)
        first[x]=n;
    for(int i=0; i<v[x].size(); ++i)
    {
        euler(v[x][i],y+1);
        ++n;
        e[n]=x;
        lev[n]=y;
    }
}

int main()
{
    p[0]=1;
    for(i=1; i<25; ++i)
        p[i]=p[i-1]*2;

    f>>n>>m;
    for(i=1; i<=n; ++i)
        f>>puncte[i];

    for(i=1; i<n; ++i)
    {
        f>>x>>y;
        v[x].push_back(y);
        boss[y]=1;
    }

    for(i=1; i<=n; ++i)
        if(boss[i]==0)
        {
            r=i;
            break;
        }

    n=0;
    euler(r,1);

    for(i=1; i<=n; ++i)
        rmq[0][i]=i;

    k = log2(n);

    for(i=1; i<=k; ++i)
        for(j=1; j<=n; ++j)
        {
            if(lev[rmq[i-1][j]] < lev[rmq[i-1][j+p[i-1]+1]])
                rmq[i][j]=rmq[i-1][j];
            else
                rmq[i][j]=rmq[i-1][j+p[i-1]+1];
        }

    for(i=1; i<=m; ++i)
    {
        f>>x>>y;
        a=first[x];
        b=first[y];
        if(b<a)
            swap(a,b);
        l=log2(b-a+1);
        if(lev[rmq[l][a]] < lev[rmq[l][b-p[l]+1]])
            q=rmq[l][a];
        else
            q=rmq[l][b-p[l]+1];
        if(puncte[e[q]] > mx)
        {
            mx=puncte[e[q]];
            xf=x;
            yf=y;
        }
        else
        if(puncte[e[q]]==mx)
        {
            if(x<xf)
            {
                xf=x;
                yf=y;
            }
            else
            if(y<yf)
            {
                yf=y;
            }
        }
    }
    g<<mx<<' '<<xf<<' '<<yf;
}
