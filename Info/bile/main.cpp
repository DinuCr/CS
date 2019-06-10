#include <iostream>
#include <fstream>
#include <utility>

using namespace std;

#define nmax 70000

struct pair1
{
    int f,s;
};

ifstream fin("bile.in");
ofstream fout("bile.out");

pair1 in[nmax];
int t[nmax];
int ans[nmax];
int nr[nmax];
int v[260][260];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int n,i,j,ok,k,mx;

int root(int x)
{
    if(!t[x])
        return x;
    t[x]=root(t[x]);
    return t[x];
}

int main()
{
    fin>>n;
    int m=n;
    n=n*n;
    for(i=1; i<=n; ++i)
        fin>>in[i].f>>in[i].s;
    for(;n>1;--n)
    {
        i=in[n].f;
        j=in[n].s;
        v[i][j]=1;
        ok=0;
        for(k=0; k<4; ++k)
            if(v[i+dx[k]][j+dy[k]])
            {
                ok++;
                if(ok==1)
                {
                    if(root((i-1)*m+j)!=root((i+dx[k]-1)*m+(j+dy[k])))
                    {
                        t[root((i-1)*m+j)]=root((i+dx[k]-1)*m+(j+dy[k]));
                        nr[root((i-1)*m+j)]++;
                    }
                    mx=max(mx,nr[root((i-1)*m+j)]);
                }
                else
                {
                    if(root((i-1)*m+j)!=root((i+dx[k]-1)*m+(j+dy[k])))
                    {
                        nr[root((i+dx[k]-1)*m+(j+dy[k]))]+=nr[root((i-1)*m+j)];
                        t[root((i-1)*m+j)]=root((i+dx[k]-1)*m+(j+dy[k]));
                    }
                    mx=max(mx,nr[root((i-1)*m+j)]);
                }
            }
        if(!ok)
        {
            nr[(i-1)*m+j]=1;
            mx=max(mx,nr[root((i-1)*m+j)]);
        }
        ans[n-1]=mx;
    }
    int x=m*m;
    for(i=1; i<=x; ++i)
        fout<<ans[i]<<'\n';
}
