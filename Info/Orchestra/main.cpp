#include <iostream>

using namespace std;
int v[15][15],i,j,x,y,r,c,k,n,nr;
int main()
{
    cin>>r>>c>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        v[x][y]=1;
    }
    for(i=1;i<=r;i++)
    for(j=1;j<=c;j++)
    v[i][j]=v[i][j]+v[i-1][j]+v[i][j-1]-v[i-1][j-1];
    for(x=1;x<=r;x++)
    for(y=1;y<=c;y++)
    if(x*y>=k)
    {
        for(i=1;i<=r-x+1;i++)
        for(j=1;j<=c-y+1;j++)
        {
            if(v[i+x-1][j+y-1]+v[i-1][j-1]-v[i+x-1][j-1]-v[i-1][j+y-1]>=k)
                nr++;
        }
    }
    cout<<nr;
}
