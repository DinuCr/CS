#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("vila.in");
ofstream fout("vila.out");

#define nmax 150

int v[nmax][nmax];
int ord[nmax][nmax];
int siz[nmax][nmax];
int mn,mx,nr,n,m,i,j;

struct nod
{
    int ord,siz;
};

nod w[5];
int dx[4]={1,-1,0,0},k,dy[4]={0,0,1,-1};

void fil(int i,int j)
{
    if(!v[i][j])
    {
        v[i][j]=-1;
        ++mn;
        fil(i+1,j);
        fil(i,j+1);
        fil(i-1,j);
        fil(i,j-1);
        ord[i][j]=nr;
    }
}

void fil1(int i,int j,int k)
{
    if(v[i][j]==-1)
    {
        v[i][j]=2;
        siz[i][j]=k;
        fil1(i+1,j,k);
        fil1(i,j+1,k);
        fil1(i-1,j,k);
        fil1(i,j-1,k);
    }
}

bool compare(nod a,nod b)
{
    return a.ord<b.ord;
}

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            char c;
            fin>>c;
            switch(c)
            {
            case '1':
                v[i][j]=1;
                break;
            default:
                v[i][j]=0;
                break;
            }
        }
    for(i=1; i<=n; ++i)
        v[i][0]=v[i][m+1]=1;
    for(j=1; j<=m; ++j)
        v[0][j]=v[n+1][j]=1;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(v[i][j]==0)
            {
                mn=0;
                fil(i,j);
                fil1(i,j,mn);
                ++nr;
                mx=max(mn,mx);
            }
    fout<<nr<<'\n'<<mx<<'\n';
    int i0=0,j0=0;
    nr=0;
    mx=0;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(v[i][j]==1)
            {
                int z=0;
                for(k=0; k<4; ++k)
                    if(v[dx[k]+i][dy[k]+j]==2)
                    {
                        w[z].ord=ord[dx[k]+i][dy[k]+j];
                        w[z].siz=siz[dx[k]+i][dy[k]+j];
                        ++z;
                    }
                if(z)
                {
                    sort(w,w+z,compare);
                    nr=1+w[0].siz;
                    for(k=1; k<z; ++k)
                        if(w[k].ord!=w[k-1].ord)
                        {
                            nr+=w[k].siz;
                        }
                    if(nr>mx)
                    {
                        mx=nr;
                        i0=i;
                        j0=j;
                    }
                }
            }
    fout<<i0<<' '<<j0<<' '<<mx;
}
