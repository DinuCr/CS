#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define pb push_back

ifstream fin("input.txt");
ofstream fout("output.txt");

struct matrice
{
    int su,jo,st,dr;
};

vector <int> su[1100];
vector <int> jo[1100];
vector <int> st[1100];
vector <int> dr[1100];

matrice v[55];
int viz[55];
int ans[15][15];
int a,b,n,i,j,ok=0;

void bkt(int x,int y,int z)
{
    if(z == b*b + 1)
    {
        for(int i=1; i<=b; ++i)
        {
            for(int j=1; j<=b; ++j)
                fout<<ans[i][j]-1<<' ';
            fout<<'\n';
        }
        ok=1;
    }
    else
    {
        if(x==1 && y==1)
        {
            for(int i=1; i<=n && !ok; ++i)
            {
                ans[1][1]=i;
                viz[i]=1;
                bkt(x,y+1,z+1);
                viz[i]=0;
            }
        }
        else
        {
            if(x==1)
            {
                for(auto it:st[v[ans[x][y-1]].dr])
                {

                    if(viz[it])
                        continue;
                    if(ok)
                        break;
                    ans[x][y]=it;
                    viz[it]=1;
                    if(y<b)
                        bkt(x,y+1,z+1);
                    else
                        bkt(x+1,1,z+1);
                    viz[it]=0;
                }
            }
            else
            {
                if(y==1)
                {
                    for(auto it:su[v[ans[x-1][y]].jo])
                    {

                        if(viz[it])
                            continue;
                        if(ok)
                            break;
                        ans[x][y]=it;
                        viz[it]=1;
                        bkt(x,y+1,z+1);
                        viz[it]=0;
                    }
                }
                else
                {
                    for(auto it:st[v[ans[x][y-1]].dr])
                        if(v[it].su==v[ans[x-1][y]].jo && !ok)
                        {
                            if(viz[it])
                                continue;
                            ans[x][y]=it;
                            viz[it]=1;
                            if(y<b)
                                bkt(x,y+1,z+1);
                            else
                                bkt(x+1,1,z+1);
                            viz[it]=0;
                        }
                }
            }
        }
    }
}


int main()
{
    fin>>a>>b>>n;
    int w[15][15];
    for(int k=1; k<=n; ++k)
    {
        for(i=0; i<a; ++i)
            for(j=0; j<a; ++j)
            {
                char c;
                fin>>c;
                w[i][j]=c-'0';
            }
        for(i=0; i<a; ++i)
        {
            v[k].su = v[k].su + w[0][i]*(1<<i);
            v[k].jo = v[k].jo + w[a-1][i]*(1<<i);
            v[k].st = v[k].st + w[i][0]*(1<<i);
            v[k].dr = v[k].dr + w[i][a-1]*(1<<i);
        }
        su[v[k].su].pb(k);
        jo[v[k].jo].pb(k);
        dr[v[k].dr].pb(k);
        st[v[k].st].pb(k);
    }
    bkt(1,1,1);
}
