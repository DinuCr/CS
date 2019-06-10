#include <iostream>
#include <fstream>
using namespace std;
const int x[8]= {-1,1,2,2,1,-1,-2,-2};
const int y[8]= {2,2,1,-1,-2,-2,-1,1};
int t[150][150],Mutari,i,j,n,m,i0,j0;

ifstream f("saritura_calului1.in");
ofstream g("saritura_calului1.out");

int Numar(int l,int c)
{
    int nr=0,i;
    for(i=0; i<=7; i++)
        if(l+x[i]>=1&&
                l+x[i]<=n&&
                c+y[i]>=1&&
                c+y[i]<=m&&
                t[l+x[i]][c+y[i]]==0)
            nr++;
    return nr;
}
void Mut(int l,int c)
{
    int i,mn,v,linie,coloana,gasit;
    t[l][c]=Mutari+1;
    gasit=0;
    mn=9;
    for(i=0; i<=7; i++)
        if(l+x[i]>=1&&
                l+x[i]<=n&&
                c+y[i]>=1&&
                c+y[i]<=m&&
                t[l+x[i]][c+y[i]]==0)
        {
            v=Numar(l+x[i],c+y[i]);
            if(v<mn)
            {
                mn=v;
                linie=l+x[i];
                coloana=c+y[i];
                gasit=1;
            }
        }
    if(gasit)
    {
        Mutari++;
        Mut(linie,coloana);
    }
}
main()
{
    f>>n>>m>>i0>>j0;

    Mut(i0,j0);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
            g<<t[i][j]<<" ";
        g<<endl;
    }

}


/*#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("saritura_calului1.in");
ofstream fout("saritura_calului1.out");

int v[110][110];
int dx[8]= {1,2,2,1,-1,-2,-2,-1},dy[8]= {-2,-1,1,2,2,1,-1,-2};
int s,n,m,i0,j0,mx;

int acces(int i,int j)
{
    int nr=0;
    for(int k=0; k<8; ++k)
    {
        if(i+dx[k]<=n && i+dx[k]>0 && j+dy[k]<=m && j+dy[k]>0)
            if(v[i+dx[k]][j+dy[k]]==0)
            {
                ++nr;
            }
    }
    return nr;
}

void bkt(int i,int j)
{
    int k1=0;
    v[i][j]=s;
    if(s==n*m)
    {
        for(int a=1; a<=n; ++a)
        {
            for(int b=1; b<=m; ++b)
                fout<<v[a][b]<<' ';
            fout<<'\n';
        }
        return ;
    }
    for(int k=0; k<8 && mx!=n*m; ++k)
    {
        int mn=-1;
        if(i+dx[k]<=n && i+dx[k]>0 && j+dy[k]<=m && j+dy[k]>0)
            if(v[i+dx[k]][j+dy[k]]==0)
            {
                if(acces(i+dx[k],j+dy[k])>mn)
                {
                    k1=k;
                    mn=acces(i+dx[k],j+dy[k]);
                }
            }
    }
    ++s;
    bkt(i+dx[k1],j+dy[k1]);
}

int main()
{
    fin>>n>>m>>i0>>j0;
    v[i0][j0]=1;
    s=1;
    bkt(i0,j0);
}*/
