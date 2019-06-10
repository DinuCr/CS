#include <fstream>
#include <stdio.h>

using namespace std;

FILE *fc = fopen("alpin.in","r");
ofstream g("alpin.out");

int v[1030][1030],d[1030][1030];
struct nod
{
    int x,y;
}q[6000000];
nod r[2000100];

#define DIM 10000
char buff[DIM];
int poz=0;

void citeste(int &numar)
{
     numar = 0;
     //cat timp caracterul din buffer nu e cifra ignor
     while (buff[poz] < '0' || buff[poz] > '9')
          //daca am "golit" bufferul atunci il umplu
          if (++poz == DIM)
               fread(buff,1,DIM,fc),poz=0;
     //cat timp dau de o cifra recalculez numarul
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fread(buff,1,DIM,fc),poz=0;
     }
}

void f(int i,int j)
{
    int n=1,k;
    q[0].x=i;
    q[0].y=j;
    int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
    d[i][j]=1;
    for(i=0; i<n; ++i)
    {
        for(k=0; k<4; ++k)
            if(v[q[i].x+dx[k]][q[i].y+dy[k]]>v[q[i].x][q[i].y] && (d[q[i].x+dx[k]][q[i].y+dy[k]]<=d[q[i].x][q[i].y] || d[q[i].x+dx[k]][q[i].y+dy[k]]==0))
            {
                d[q[i].x+dx[k]][q[i].y+dy[k]]=d[q[i].x][q[i].y]+1;
                q[n].x=q[i].x+dx[k];
                q[n++].y=q[i].y+dy[k];
            }
    }
}

void drum(int i, int j)
{
    r[0].x=i;
    r[0].y=j;
    int R=1;
    int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0},k;
    while(d[i][j] > 1)
    {
        for(k=0; k<4; ++k)
            if(d[i+dx[k]][j+dy[k]]==d[i][j]-1)
            {
                i+=dx[k];
                j+=dy[k];
                r[R].x=i;
                r[R++].y=j;
            }
    }
    for(i=R-1; i>=0; --i)
        g<<r[i].x<<' '<<r[i].y<<'\n';\

}
int main()
{
    int n,i,j,mx=0,i0,j0;

    citeste(n);
    ++n;
    for(i=1; i<n; ++i)
        v[0][i]=v[i][0]=v[n][i]=v[i][n]=d[0][i]=d[i][0]=d[n][i]=d[i][n]=10000000;

    for(i=1; i<n; ++i)
        for(j=1; j<n; ++j)
            citeste(v[i][j]);

    for(i=1; i<n; ++i)
        for(j=1; j<n; ++j)
            if(!d[i][j] && v[i][j]<v[i+1][j] && v[i][j]<v[i-1][j] && v[i][j]<v[i][j-1] && v[i][j]<v[i][j+1])
                f(i,j);

    for(i=1; i<n; ++i)
        for(j=1; j<n; ++j)
            if(d[i][j]>mx)
            {
                mx=d[i][j];
                i0=i;
                j0=j;
            }
    g<<mx<<'\n';
    drum(i0,j0);
}
