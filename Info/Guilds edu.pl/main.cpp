#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#define nmax 200100
#define pb push_back

int n,m,i,a,b,ok,nr;

vector <int> v[nmax];
char viz[nmax];

char inv(char c)
{
    switch(c)
    {
    case 'K':
        return 'S';
    case 'S':
        return 'K';
    }
}

void df(int x)
{
    ++nr;
    for(int i=0; i<v[x].size(); ++i)
    {
        if(viz[v[x][i]]==NULL)
        {
            viz[v[x][i]]=inv(viz[x]);
                df(v[x][i]);
        }
    }
}


int main()
{
    cin>>n>>m;
    for(i=0; i<m; ++i)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int ok=1;
    for(i=1; i<=n; ++i)
    if(viz[i]==NULL)
    {
        nr=0;
        viz[i]='K';
        df(i);
        if(nr==1)
            ok=0;
    }
    if(ok)
    {
        cout<<"TAK\n";
        for(i=1; i<=n; ++i)
            cout<<viz[i]<<'\n';
    }
    else
    cout<<"NIE";
}
