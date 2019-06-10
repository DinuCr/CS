#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("darb.in");
ofstream g("darb.out");

vector <int> v[100100];
int viz[100100];
int c[100100];
int k,x,n,i,j;

void df1(int a)
{
    k=1;
    c[k]=a;
    viz[a]=-1;

    for(i=1; i<=k; ++i)
    {
        for(j=0; j<v[c[i]].size(); ++j)
            if(viz[v[c[i]][j]]==0)
            {
                c[++k]=v[c[i]][j];
                viz[v[c[i]][j]]=-1;
            }
    }

    x=c[k];
}

void df2(int a)
{
    k=1;
    c[k]=a;
    viz[a]=1;

        for(i=1; i<=k; ++i)
    {
        for(j=0; j<v[c[i]].size(); ++j)
            if(viz[v[c[i]][j]]==-1)
            {
                c[++k]=v[c[i]][j];
                viz[v[c[i]][j]]=viz[c[i]]+1;
            }
    }

    g<<viz[c[k]];

}

int main()
{
    f>>n;
    int a,b;
    for(i=1; i<n; ++i)
    {
        f>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    df1(1);
    df2(x);
}
