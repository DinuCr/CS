#include<iostream>
using namespace std;
int x[8]={-2,-1,1,2,2,1,-1,-2},y[8]={1,2,2,1,-1,-2,-2,-1},st[1000][2],v[1000][1000],i,j,k,i2,j2,i1,j1,n,n2;
int main()
{
    cin>>i1>>j1>>i2>>j2>>n2;
    i1+=1;j1+=1;i2+=1;j2+=1;n2++;
    st[1][0]=i1;
    st[1][1]=j1;
    v[i1][j1]=1;
    n=1;
    for(i=0;i<=n2+2;i++)
    {
        v[i][n2+1]=-1;
        v[n2+1][i]=-1;
        v[i][0]=-1;
        v[0][i]=-1;

        v[i][n2+2]=-1;
        v[n2+2][i]=-1;
        v[i][1]=-1;
        v[1][i]=-1;

    }
    for(i=1;i<=n;i++)
    {
        if(st[i][0]==i2 && st[i][1]==j2)
            break;
        else
        {
            for(j=0;j<8;j++)
            {
                if(v[st[i][0]+x[j]][st[i][1]+y[j]]==0)
                {
                    v[st[i][0]+x[j]][st[i][1]+y[j]]=v[st[i][0]][st[i][1]]+1;
                    n++;
                    st[n][0]=st[i][0]+x[j];
                    st[n][1]=st[i][1]+y[j];
                }
            }
        }
    }
    i=i2;j=j2;
    cout<<v[i][j]-1<<'\n';
    while(i!=i1 || j!=j1)
    {
        cout<<i-1<<' '<<j-1<<'\n';
        for(k=0;k<8;k++)
            {
                if(v[i+x[k]][j+y[k]]==v[i][j]-1)
                {
                    i+=x[k];
                    j+=y[k];
                    break;
                }
            }
    }
    cout<<i1-1<<' '<<j1-1;
    return 0;
}
