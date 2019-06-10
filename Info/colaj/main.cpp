/*#include <iostream>
#include <fstream>*/
#include <bits/stdc++.h>
using namespace std;
typedef struct coord
{
    int xs,ys,xd,yd;
};
coord v[110];
bool w[210][210];
int n,m,p,k,nr,x[210],y[210];
void fill1(int i,int j)
{
    if(!w[i][j])
    {
        w[i][j]=1;
        fill1(i,j+1);
        fill1(i,j-1);
        fill1(i+1,j);
        fill1(i-1,j);
    }
}
void sort1(int v[])
{
    int ok=1;
    while(ok)
    {
        ok=0;
        for(int i=1;i<k;i++)
            if(v[i]>v[i+1])
            swap(v[i],v[i+1]),ok=1;
    }
}
int main()
{
    ifstream f("colaj.in");
    ofstream g("colaj.out");
    f>>p>>n>>m;
    for(int i=1;i<=p;++i)
    {
        f>>v[i].xs>>v[i].ys>>v[i].xd>>v[i].yd;
        x[++k]=v[i].xs;
        y[k]=v[i].ys;
        x[++k]=v[i].xd;
        y[k]=v[i].yd;
    }
    int n2=p;
    sort1(x);
    sort1(y);
    for(int i=0;i<k;i++)
    for(int j=0;j<k;j++)
    {
        for(p=1;p<=n2;p++)
        if(x[i]<=v[p].xd && x[i]>=v[p].xs && x[i+1]<=v[p].xd && x[i+1]>=v[p].xs)
        if(y[j]<=v[p].yd && y[j]>=v[p].ys && y[j+1]<=v[p].yd && y[j+1]>=v[p].ys)
        {
            w[i+1][j+1]=1;
            break;
        }
    }
    if(x[k]==n)
        n=k+1;
    else
        n=k+2;
    if(y[k]==m)
        m=k+1;
    else
        m=k+2;

    for(int i=1;i<=k+2;i++)
    {
        w[0][i]=1;
        w[i][0]=1;
        w[n][i]=1;
        w[i][m]=1;
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(!w[i][j])
    {
        nr++;
        fill1(i,j);
    }
    g<<nr;


}
