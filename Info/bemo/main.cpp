#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("bemo.in");
ofstream fout("bemo.out");

#define mp make_pair
#define f first
#define s second

pair <int,int> v[2300000];
int ans[3100];
int n,m,i,j;

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            int x;
            fin>>x;
            v[x]=mp(i,j);
        }
    int lim = n*m;
    for(i=1; i<=lim; ++i)
    {
        if(!ans[v[i].f+v[i].s-1])
        {
            int a = v[i].f+v[i].s-1;
            int ok=1;
            while(a>0)
            {
                if(ans[a]!=0)
                {
                    if(v[ans[a]].f>v[i].f || v[ans[a]].s>v[i].s)
                    {
                        ok=0;
                        break;
                    }
                    else
                    break;
                }
                --a;
            }
            if(ok)
            {
                a=v[i].f+v[i].s-1;
                while(a<n+m)
                {
                    if(ans[a]!=0)
                    {
                        if(v[ans[a]].f<v[i].f || v[ans[a]].s<v[i].s)
                        {
                            ok=0;
                            break;
                        }
                        else
                        break;
                    }
                    ++a;
                }
            }
            if(ok)
                ans[v[i].f+v[i].s-1]=i;
        }
    }
    for(i=1; i<n+m; ++i)
        fout<<ans[i]<<' ';
}
