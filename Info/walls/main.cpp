#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

#define pb push_back

ifstream fin("walls.in");

int start[35];

vector <int> v[205];
vector <int> reg[205];
vector <int> t[255];
int d[35][205];
int i,j,n,m,l;

void muchii(int a,int b)
{
    int i,j;
    for(i=0; i<reg[a].size()-1; ++i)
        for(j=0; j<reg[b].size()-1; ++j)
            if((reg[a][i]==reg[b][j] && reg[a][i+1]==reg[b][j+1]) || (reg[a][i+1]==reg[b][j] && reg[a][i]==reg[b][j+1]))
            {
                v[a].pb(b);
                v[b].pb(a);
                return ;
            }

}

int main()
{
    cin>>m>>n>>l;
    for(i=1; i<=l; ++i)
        cin>>start[i];
    for(i=1; i<=m; ++i)
    {
        int n2;
        cin>>n2;
        while(n2--)
        {
            int x;
            cin>>x;
            reg[i].pb(x);
        }
        reg[i].pb(reg[i][0]);
        for(j=1; j<i; ++j)
            muchii(j,i);
    }
    for(i=1; i<=m; ++i)
        sort(reg[i].begin(),reg[i].end());
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=m; ++j)
            if(binary_search(reg[j].begin(),reg[j].end(),i))
                t[i].pb(j);
    }
    queue <int> q;
    for(i=1; i<=l; ++i)
    {
        for(j=1; j<=m; ++j)
            d[i][j]=LONG_MAX;
        for(auto it:t[start[i]])
        {
            d[i][it]=0;
            q.push(it);
        }
        while(!q.empty())
        {
            int nod = q.front();
            q.pop();
            for(auto it:v[nod])
            {
                if(d[i][it]>d[i][nod]+1)
                {
                    q.push(it);
                    d[i][it]=d[i][nod]+1;
                }
            }
        }
    }
    int ans = LONG_MAX;
    int ans2;
    for(i=1; i<=m; ++i)
    {
        int curr = 0;
        for(j=1; j<=l; ++j)
            curr+=d[j][i];
        if(curr<ans)
        {
            ans = curr;
            ans2 = i;
        }
    }
    cout<<ans<<'\n'<<ans2;
}
