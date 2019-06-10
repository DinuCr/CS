#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("ciclu2.in");
ofstream fout("ciclu2.out");

#define nmax 210

vector <int> v[nmax];
int ad[nmax][nmax];
int i,ok,a,b,length,n,m,t;

void bkt(int x,int l)
{
    if(!ok && l<length)
    {
        if(l==length-1 && ad[x][a])
        {
            ok=1;
            return;
        }
        for(int i=0; i<v[x].size(); ++i)
            if(ad[x][v[x][i]])
            {
                ad[x][v[x][i]]=0;
                ad[v[x][i]][x]=0;

                bkt(v[x][i],l+1);

                ad[x][v[x][i]]=1;
                ad[v[x][i]][x]=1;
            }
    }
}

int main()
{
    fin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        fin>>a>>b;
        ad[a][b]=ad[b][a]=1;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    fin>>t;
    while(t--)
    {
        fin>>a>>length;
        ok=0;
        bkt(a,0);
        fout<<ok<<'\n';
    }
}
