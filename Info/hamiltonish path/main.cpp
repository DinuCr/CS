#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector <int> v[100010];
int used[100010];
deque <int> ans;

void df1(int x)
{
    used[x]=1;
    ans.push_back(x);
    for(auto it:v[x])
        if(!used[it])
        {
            df1(it);
            return;
        }
}

void df2(int x)
{
    used[x]=1;
    if(x!=1)
    ans.push_front(x);
    for(auto it:v[x])
        if(!used[it])
        {
            df2(it);
            return;
        }
}

int main()
{
    int i,n,m,a,b;
    cin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    df1(1);
    df2(1);
    cout<<ans.size()<<'\n';
    for(auto it:ans)
        cout<<it<<' ';
}
