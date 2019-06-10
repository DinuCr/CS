#include <iostream>
#include <vector>

using namespace std;

#define nmax 150010

vector <int> v[nmax];
int viz[nmax];
long long nr,muchii,i,n,m;

void df(int x)
{
    viz[x]=1;
    ++nr;
    muchii+=v[x].size();
    for(auto it:v[x])
        if(!viz[it])
            df(it);
}

int main()
{
    cin>>n>>m;
    int a,b;
    for(i=1; i<=m; ++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1; i<=n; ++i)
    if(!viz[i])
    {
        nr=0;
        muchii=0;
        df(i);
        if(nr*(nr-1)!=muchii)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}
