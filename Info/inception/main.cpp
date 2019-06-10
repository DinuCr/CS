#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
ifstream f("inception.in");
ofstream g("inception.out");
int v[20][300100],val[300100],r[300100],x,n,q,k,nr,va,p,i,id,j;
vector <int> arb[300100];
typedef struct case2
{
    int val,nr,id;
};
case2 z;
vector <case2> adval;
void dfs(int id)
{
    for(vector <int>::iterator i=arb[id].begin();i<arb[id].end();i++)
    {
        dfs(*i);
        val[id]+=val[*i];
    }
    r[id]+=val[id];
}
int main()
{
    f>>n>>q>>k;
    int m=1,a;
    for(i=1;i<=q;i++)
    {
        f>>p;
        switch(p)
        {
        case 1:
            m++;
            f>>id>>a>>a;
            arb[id].push_back(m);
            v[0][m]=id;
            break;
        case 2:
            f>>z.id>>z.nr>>z.val;
            adval.push_back(z);
            break;
        }
    }
    int k2=log2(m);
    for(i=1;i<=k2;i++)
    for(j=1;j<=m;j++)
    v[i][j]=v[i-1][v[i-1][j]];

    int nr2;
    for(i=0;i<adval.size();i++)
    {
        val[adval[i].id]+=adval[i].val;
        id=adval[i].id;
        nr=adval[i].nr;
        while(nr)
        {
            nr2=log2(nr);
            nr-=(1<<nr2);
            id=v[nr2][id];
        }
        val[id]-=adval[i].val;
    }
    dfs(1);
    for(i=1;i<=k;i++)
        f>>x,g<<r[x]<<' ';
}
