#include<iostream>
#include<fstream>
using namespace std;
ifstream f("ferma3.in");
ofstream g("ferma3.out");
int n,m,p,i,j,nr,w[405][405],d[405][405],v1,mx,x[4]= {0,0,-1,1},y[4]= {1,-1,0,0},a,b,l1,c1;
char q,k[6],v[405][405];
void fill1(int i,int j)
{
    nr++;
    w[i][j]=1;
    if(!w[i+1][j] && v[i][j]==v[i+1][j])
        fill1(i+1,j);
    if(!w[i-1][j] && v[i][j]==v[i-1][j])
        fill1(i-1,j);
    if(!w[i][j+1] && v[i][j]==v[i][j+1])
        fill1(i,j+1);
    if(!w[i][j-1] && v[i][j]==v[i][j-1])
        fill1(i,j-1);
    w[i][j]=nr;
    d[i][j]=p;
}
int main()
{
    f>>v1>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            f>>q;
            v[i][j]=q;
        }
    p=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(!w[i][j])
            {
                nr=0;
                p++;
                fill1(i,j);
                mx=max(nr,mx);
            }
    if(v1==1)
        g<<mx;
    else
    {
        mx=0;
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
            {
                for(a=0; a<4; a++)
                    if(v[i+x[a]][j+y[a]]==v[i][j])
                        k[a]=0;
                    else
                        k[a]=v[i+x[a]][j+y[a]];
                for(a=0; a<3; a++)
                    if(k[a]>0)
                    {
                        nr=1+w[i+x[a]][j+y[a]];
                        for(b=a+1; b<4; b++)
                            if(k[a]==k[b])
                            {
                                if(d[i+x[a]][j+y[a]]!=d[i+x[b]][j+y[b]])
                                    nr+=w[i+x[b]][j+y[b]];
                            }
                        if(nr>mx)
                        {
                            mx=nr;
                            l1=i;
                            c1=j;
                            q=k[a];
                        }
                    }
            }
        g<<l1<<' '<<c1<<'\n'<<q;
    }
}
