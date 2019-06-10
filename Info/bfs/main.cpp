#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define pb push_back
vector <int> v[100100];
queue <int> q;
int t,n,m,a,b,i,viz[100100];
int main()
{
    freopen("bfs.in","r",stdin);
    freopen("bfs.out","w",stdout);
    scanf("%d%d%d",&n,&m,&t);
    for(i=0; i<m; ++i)
    {
        scanf("%d%d",&a,&b);
        v[a].pb(b);
    }
    viz[t]=1;
    q.push(t);
    while(!q.empty())
    {
        for(int j=0; j<v[q.front()].size(); ++j)
        {
            if(!viz[v[q.front()][j]])
            {
                q.push(v[q.front()][j]);
                viz[v[q.front()][j]]=viz[q.front()]+1;
            }
        }
        q.pop();
    }
    for(i=1; i<=n; ++i)
    {
        v[i].clear();
        printf("%d ",viz[i]-1);
        viz[i]=0;
    }
    printf("\n");
}
