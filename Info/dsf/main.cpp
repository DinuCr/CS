#include <cstdio>
#include <vector>
using namespace std;
vector <int> v[100010];
bool w[100010];
void df(int x)
{
    int i;
    w[x]=1;
    for(i=0; i<v[x].size(); ++i)
        if(!w[v[x][i]])
            df(v[x][i]);
}
int main()
{
    freopen("dfs.in","r",stdin);
    freopen("dfs.out","w",stdout);
    int n,m,a,b,i,N=0;
    scanf("%d%d",&n,&m);
    for(i=0; i<m; ++i)
    {
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1; i<=n; ++i)
        if(!w[i])
        {
            ++N;
            df(i);
        }
    printf("%d",N);
}
