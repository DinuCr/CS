#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("karb2.in");
ofstream fout("karb2.out");

const int modulo = 666013;

#define nmax 100010
#define mp make_pair
#define f first
#define s second

vector <int> v[nmax];
vector <pair<int,int> > w[nmax];
int kartel[nmax];
int d[nmax][2];

inline int mod(long long x)
{
    if(x>=modulo)
        return x%modulo;
    return x;
}

void df(int x,int t)
{
    ///d[0] - influentat de subarbore
    ///d[1] - influentat din afara
    if(kartel[x])
    {
        d[x][0]=1;
        for(auto it:v[x])
            if(it!=t)
            {
                df(it,x);
                d[x][0]=mod(1LL*d[x][0]*(d[it][0]+d[it][1]));
            }
        if(!v[x].size())
            d[x][0]=1;
        return ;
    }
    if(!v[x].size())
    {
        d[x][1]=1;
        return ;
    }
    d[x][1]=1;

    for(int i=0; i<v[x].size(); ++i)
        if(v[x][i]==t)
        {
            swap(v[x][i],v[x][v[x].size()-1]);
            v[x].pop_back();
            break;
        }

    w[x].push_back(mp(1,1));
    for(int i=0,it=v[x][0]; i<v[x].size(); ++i,it=v[x][i])
    {
        df(it,x);
        d[x][1]=mod(1LL*d[x][1]*(d[it][0]+d[it][1]));
        if(i>0)
            w[x].push_back(mp(mod(1LL*w[x].back().f*(d[v[x][i-1]][0]+d[v[x][i-1]][1])),0));
    }
    w[x].back().s = 1;
    for(int i=v[x].size()-2; i>=0; --i)
        w[x][i].s = mod(1LL*w[x][i+1].s * (d[v[x][i+1]][0]+d[v[x][i+1]][1]) );
    for(int i=v[x].size()-1,it=v[x].back(); i>=0; --i,it=v[x][i])
        d[x][0]=mod(d[x][0]+1LL*w[x][i].f*d[it][0]*w[x][i].s);
}

int main()
{
    int n,m,i;
    fin>>n>>m;
    int x,y;
    for(i=1; i<=m; ++i)
    {
        fin>>x;
        kartel[x]=1;
    }
    for(i=1; i<n; ++i)
    {
        fin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    df(1,0);
    fout<<d[1][0];
}
