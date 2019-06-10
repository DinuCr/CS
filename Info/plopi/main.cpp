#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("plopi.in");
ofstream fout("plopi.out");

#define nmax 100100
#define f first
#define s second

vector < pair<int,int> > v[nmax];
int d[nmax];
int n,nr1,nr2,a,b,c,i;

void df(int x)
{
    for(int i=0; i<v[x].size(); ++i)
        if(d[v[x][i].f]==0)
        {
            d[v[x][i].f]=d[x]+v[x][i].s;
            df(v[x][i].f);
        }
}

int main()
{
    fin>>n;
    for(i=1; i<n; ++i)
    {
        fin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    df(1);
    d[1]=2;
    for(i=1; i<=n; ++i)
        if((d[i]&1)==0)
            nr1++;
        else
            nr2++;
    fout<<1LL*nr1*nr2;
}
