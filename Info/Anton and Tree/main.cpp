#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int color[200100];
vector <int> v[200100];
int viz[200100],n,mx,i,nod;

void diameter(int x,int last,int nr)
{
    if(color[x]!=last)
        ++nr;
    if(nr>mx)
    {
        mx=nr;
        nod=x;
    }
    viz[x]=1;
    for(int i=0; i<v[x].size(); ++i)
        if(viz[v[x][i]]==0)
            diameter(v[x][i],color[x],nr);
}

void diameter1(int x,int last,int nr)
{
    if(color[x]!=last)
        ++nr;
    mx=max(mx,nr);
    viz[x]=0;
    for(int i=0; i<v[x].size(); ++i)
        if(viz[v[x][i]]==1)
            diameter1(v[x][i],color[x],nr);
}


int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>color[i];

    for(i=1; i<n; ++i)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    diameter(1,!color[1],0);
    diameter1(nod,!color[nod],0);
    cout<<mx/2;
}
