#include <iostream>

using namespace std;
int n,m,v[510][510],i,j,w[510][510],p,a,b,c,d;
char x;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        cin>>x;
        if(x=='.')
            v[i][j]=1;
        else
            v[i][j]=2;
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(v[i][j]==1)
    {
        if(v[i-1][j]==1)
            w[i][j]++;
        if(v[i][j-1]==1)
            w[i][j]++;
        w[i][j]=w[i][j]+w[i-1][j]+w[i][j-1]-w[i-1][j-1];
    }
    else
        w[i][j]=w[i-1][j]+w[i][j-1]-w[i-1][j-1];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<w[i][j]<<' ';
        cout<<endl;
    }
    cin>>p;
    for(i=1;i<=p;i++)
    {
        cin>>a>>b>>c>>d;
        cout<<w[c][d]+w[a-1][b-1]-w[a-1][d]-w[c][b-1];
    }
}
