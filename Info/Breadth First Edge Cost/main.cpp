#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define pb push_back
vector <int> v[1100];
queue <int> q;
int t,n,m,a,b,i,viz[1010];
int main()
{
    cin>>t;
    for(int k=0; k<t; ++k)
    {
        cin>>n>>m;
        for(i=0; i<m; ++i)
        {
            cin>>a>>b;
            v[a].pb(b);
            v[b].pb(a);
        }
        cin>>a;
        viz[a]=1;
        q.push(a);
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
            if(i!=a)
            {
                if(viz[i])
                    cout<<(viz[i]-1)*6<<' ';
                else
                    cout<<"-1 ";
            }
            viz[i]=0;
        }
         cout<<'\n';
    }
}
