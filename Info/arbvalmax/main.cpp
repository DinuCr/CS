#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("arbvalmax.in");
ofstream fout("arbvalmax.out");

#define nmax 300010

vector <int> v[nmax];
int d[nmax];
int up[nmax];
int down[nmax];
int val[nmax];

void df(int x)
{
    for(auto it:v[x])
    {
        up[it]=max(up[x],val[x]);
        df(it);
        down[x]=max(down[x],max(down[it],val[it]));
    }
}

void df1(int x)
{
    int a=0,b=0;
    for(auto it:v[x])
    {
        if(max(down[it],val[it])>max(val[a],down[a]))
        {
            b=a;
            a=it;
        }
        else
        if(max(down[it],val[it])>max(val[b],down[b]))
        {
            b=it;
        }
    }
    for(auto it:v[x])
    {
        if(it==a)
            d[it]=max(d[x],max(val[b],down[b]));
        else
            d[it]=max(d[x],max(val[a],down[a]));
        df1(it);
    }
}

int main()
{
    int n,m,i,a,b;
    fin>>n>>m;
    for(i=2; i<=n; ++i)
    {
        fin>>a;
        v[a].push_back(i);
    }
    for(i=1; i<=n; ++i)
        fin>>val[i];
    df(1);
    df1(1);
    while(m--)
    {
        fin>>a>>b;
        fout<<max(d[b],max(up[a],down[b]))<<'\n';
    }
}
