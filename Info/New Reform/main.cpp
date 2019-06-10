#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

bitset <100001> viz;
vector <int> v[100001];
int nr,n,m,i,j,ok,k,N;
int w[100010];

#define pb push_back

void bf(int i)
{
    if(!viz[i])
    {
        viz[i]=1;
        w[nr++]=i;
        for(int j=0; j<v[i].size(); ++j)
            bf(v[i][j]);
    }
}
int main()
{
    cin>>n>>m;
    int a,b;
    for(i=1; i<=m; i++)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(i=1; i<=n; i++)
        if(!viz[i])
        {
            nr=0;
            bf(i);
            ok=1;
            while(ok)
            {
                ok=0;
                for(j=0; j<nr; ++j)
                {

                    if(v[w[j]].size()==1)
                    {
                        ok=1;
                        for(k=0; k<v[v[w[j]][0]].size(); ++k)
                            if(v[v[w[j]][0]][k]==w[j])
                            {
                                swap(v[v[w[j]][0]][k],v[v[w[j]][0]][v[v[w[j]][0]].size()-1]);
                                v[v[w[j]][0]].pop_back();
                            }
                        swap(w[j],w[nr-1]);
                        nr--;
                    }
                }
            }
            for(j=0; j<nr; ++j)
                if(v[w[j]].size()==0)
                    N++;
        }
    cout<<N;
}
