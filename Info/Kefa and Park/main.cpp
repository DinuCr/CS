#include<iostream>
using namespace std;
int n,m,w[2501][2501],k,x,y,v[2501],st[2][2501],viz[2501],i,j,nr;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>v[i];
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        w[x][0]++;
        w[x][w[x][0]]=y;

        w[y][0]++;
        w[y][w[y][0]]=1;
    }
    k=1;
    st[k][0]=1;
    viz[k]=1;
    for(i=1;i<=k;i++)
    {
        st[i][1]=st[i][1]*v[i]+v[i];
        if(st[i][1]<=m)
        {
            for(j=1;j<=w[st[i][0]][0];j++)
            if(!viz[w[st[i][0]][j]] && v[w[st[i][0]][j]]+st[i][1]<=m)
            {
                k++;
                st[k][0]=w[st[i][0]][j];
                viz[w[st[i][0]][j]]=1;
            }
        }
        if(w[st[i][0]][0]==1 && viz[w[st[i][0]][1]]==1)
            nr++;
    }

    cout<<nr;
    return 0;
}
