#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

FILE *fin=fopen("padure.in","r");
FILE *fout=fopen("padure.out","w");

#define f first
#define s second

#define nmax 1000100

queue <pair<int,int> > q;
int v[1010][1010];
int d[1010][1010];
int n,m,i,j,p1,p2,c1,c2,start,finish,poz,k,ok;

#define DIM 10000
char buff[DIM];
int poz1=0;

void c(int &numar)
{
    numar = 0;
    while (buff[poz1] < '0' || buff[poz1] > '9')
        if (++poz1 == DIM)
            fread(buff,1,DIM,fin),poz1=0;
    while ('0'<=buff[poz1] && buff[poz1]<='9')
    {
        numar = numar*10 + buff[poz1] - '0';
        if (++poz1 == DIM)
            fread(buff,1,DIM,fin),poz1=0;
    }
}

void df(int i,int j,int x)
{
    if(!ok)
    {
        if((d[i][j]==0 || d[i][j]>k )&& v[i][j]==x )
        {
            d[i][j]=k;
            df(i+1,j,x);
            df(i-1,j,x);
            df(i,j+1,x);
            df(i,j-1,x);
        }
        else if(v[i][j]!=x && v[i][j]!=-1 &&  (d[i][j]==0 || k+1<d[i][j]))
        {
            d[i][j]=k+1;
            q.push(make_pair(i,j));
        }
        if(i==c1 && j==c2)
        {
            ok=1;
        }
    }
}


int main()
{
    c(n);
    c(m);
    c(p1);
    c(p2);
    c(c1);
    c(c2);
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            c(v[i][j]);
    for(i=1; i<=n; ++i)
        v[i][m+1]=v[i][0]=-1;
    for(i=1; i<=m; ++i)
        v[0][i]=v[n+1][i]=-1;

    q.push(make_pair(p1,p2));
    d[p1][p2]=1;
    while(!q.empty() && !ok)
    {
        i=q.front().f;
        j=q.front().s;
        q.pop();
        k=d[i][j];
        d[i][j]=0;
        df(i,j,v[i][j]);


    }
    fprintf(fout,"%d",d[c1][c2]-1);
}
