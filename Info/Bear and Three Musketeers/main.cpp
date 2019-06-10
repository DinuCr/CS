#include<iostream>
#include <fstream>
using namespace std;
ifstream f("bear.in");
int v[4010][4010],a,b,n,m,x,mn,i,j,k;
int main()
{
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        v[a][0]++;
        v[a][v[a][0]]=b;
        v[b][0]++;
        v[b][v[b][0]]=a;
    }
    mn=100000;
    for(x=1;x<=n;x++)
    {
        //am nr 1:
        for(i=1;i<=v[x][0];i++)
        {
            //am nr 2: v[x][i]
            for(j=1;j<=v[v[x][i]][0];j++)
            if(v[v[x][i]][j]!=x)
            {
                //am nr 3: v[v[x][i]][j]
                for(k=1;k<=v[v[v[x][i]][j]][0];k++)
                if(v[v[v[x][i]][j]][k]==x)
                {
                    mn=min(mn,v[x][0]+v[v[x][i]][0]+v[v[v[x][i]][j]][0]-6);
                    break;
                }
            }
        }
    }
    if(mn==100000)
    cout<<"-1";
    else
        cout<<mn;
}
