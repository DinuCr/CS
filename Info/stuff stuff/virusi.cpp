#include<iostream>
using namespace std;
int v[100][100],i,j,x,y,k,g,m,n,s;
int main()
{
    cin>>n>>m>>k>>g;
    for(i=1;i<=k;i++)
    {
        cin>>x>>y;
        v[x][y]=1;
    }
    for(k=1;k<=g;k++)
    {
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            switch(v[i][j])
            {
            case 0:
                s=v[i-1][j]+v[i+1][j]+v[i][j-1]+v[i][j+1];
                if(s==2 || s==3)
                    v[i][j]=1;
                break;
            case 1:
                s=v[i-1][j]+v[i+1][j]+v[i][j-1]+v[i][j+1];
                if(s==4)
                    v[i][j]=0;
                else
                    v[i][j]++;
                break;
            case 2:
                s=v[i-1][j]+v[i+1][j]+v[i][j-1]+v[i][j+1];
                if(s==4)
                    v[i][j]=0;
                else
                    v[i][j]++;
                break;
            case 3:
                v[i][j]=0;
                break;
            }
        }
        for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<v[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
    }
    return 0;
}
