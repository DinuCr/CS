#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("cuvinte.in");
ofstream fout("cuvinte.out");

char v[35][35];
char cuv[45][35];
int siz[45];
int used[45][35];
int n,m,nr,ok,i;

inline bool down(int i, int j, int x)
{
    if(i+siz[x]-1>n)
        return 0;
    int k;
    for(k=0; k<siz[x]; ++k)
        used[x][k]=0;
    for(k=0; k<siz[x]; ++k)
    {
        if(v[i+k][j]==0)
            used[x][k]=1;
        else
        if(v[i+k][j]!=cuv[x][k])
            return 0;
    }
    for(k=0; k<siz[x]; ++k)
        v[i+k][j]=cuv[x][k];
    return 1;
}

inline bool nex(int i,int j,int x)
{
    if(j+siz[x]-1>m)
        return 0;
    int k;
    for(k=0; k<siz[x]; ++k)
        used[x][k]=0;
    for(k=0; k<siz[x]; ++k)
    {
        if(v[i][j+k]==0)
            used[x][k]=1;
        else
        if(v[i][j+k]!=cuv[x][k])
            return 0;
    }
    for(k=0; k<siz[x]; ++k)
        v[i][j+k]=cuv[x][k];
    return 1;
}

void bkt(int k)
{
    int i,j,a;
    if(k==nr+1)
    {
        ok=0;
        for(i=1; i<=n; ++i)
        {
            for(j=1; j<=m; ++j)
                if(v[i][j]>0)
                    fout<<v[i][j]<<' ';
                else
                    fout<<"- ";
            fout<<'\n';
        }
    }
    else
    for(i=1; i<=n && ok; ++i)
        for(j=1; j<=m && ok; ++j)
        {
            if((v[i][j]==0 || v[i][j]==cuv[k][0]) && down(i,j,k))
            {
                bkt(k+1);
                for(a=0; a<siz[k]; ++a)
                    if(used[k][a]==1)
                        v[i+a][j]=0;
            }
            if((v[i][j]==0 || v[i][j]==cuv[k][0]) && ok && nex(i,j,k))
            {
                bkt(k+1);
                for(a=0; a<siz[k]; ++a)
                    if(used[k][a]==1)
                        v[i][j+a]=0;
            }
        }
}

int main()
{
    fin>>nr>>n>>m;
    ok=1;
    for(i=1; i<=nr; ++i)
    {
        fin>>cuv[i];
        siz[i]=strlen(cuv[i]);
    }
    bkt(1);
}
