#include<iostream>
#include <stdlib.h>
using namespace std;
int n,i,j,x,y,ok,m;
int main()
{
    int* spatiu=malloc(100*100);

    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        v[1][y]++;
        v[0][x]++;
        v[v[0][x]+1][x]=y;
    }
    ok=true;
    while(ok)
    {
        ok=false;
        for(i=1;i<=n;i++)
        if(v[1][i]==0)
        {
            v[1][i]=-1;
            for(j=2;j<=v[0][i]+1;j++)
            v[1][v[j][i]]--;
            cout<<i<<' ';
            ok=true;
            break;
        }
    }
    free (spatiu);
    return 0;
}
