#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <vector <int> > v;
int n,m,i,j,x,y;
vector <vector <int> > d;
int ans[100100];

int main()
{
    cin>>n>>m;
    for(i=1; i<=n; ++i)
    {
        vector <int> curr;
        for(j=1; j<=m; ++j)
        {
            cin>>x;
            curr.push_back(x);
        }
        v.push_back(curr);
        d.push_back(curr);
    }

    for(i=0; i<n; ++i)
    {
        for(j=0; j<m; ++j)
        {
            if(i==0)
                d[i][j]=0;
            else
            if(v[i][j]>=v[i-1][j])
                d[i][j]=d[i-1][j]+1;
            else
                d[i][j]=0;
            ans[i]=max(ans[i],d[i][j]);
        }
    }
    int q,a,b;
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        --a;
        --b;
        if(b-ans[b]<=a)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
