#include <iostream>
#include <stdio.h>
using namespace std;
int v[1010][1010],w[1010][1010],i,j,n,m,nr,k,s;
void fill1(int i,int j)
{
    if(v[i][j]==-2)
    {
        v[i][j]=1;
        nr++;
        w[i][j]=k;
        fill1(i,j+1);
        fill1(i+1,j);
        fill1(i-1,j);
        fill1(i,j-1);
    }
}
void fill2(int i,int j)
{
    if(v[i][j]==1)
    {

        v[i][j]=nr;
        fill2(i,j+1);
        fill2(i+1,j);
        fill2(i-1,j);
        fill2(i,j-1);

    }
}
int main()
{
    scanf("%d%d",&n,&m);
    char c;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            scanf("%c",&c);
            if(c!='\n')
            {
                if(c=='.')
                    v[i][j]=-2;
                else
                    v[i][j]=-1;
            }
            else
                j--;
        }
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            if(v[i][j]==-2)
            {
                nr=0;
                k++;
                fill1(i,j);
                fill2(i,j);
            }
        }
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=m; ++j)
            if(v[i][j]==-1)
            {
                s=1;
                if(v[i-1][j]!=-1)
                    s+=v[i-1][j];
                if(v[i+1][j]!=-1 && w[i+1][j]!=w[i-1][j])
                    s+=v[i+1][j];
                if(v[i][j-1]!=-1 && w[i+1][j]!=w[i][j-1] && w[i-1][j]!=w[i][j-1])
                    s+=v[i][j-1];
                if(v[i][j+1]!=-1 && w[i+1][j]!=w[i][j+1] && w[i-1][j]!=w[i][j+1] && w[i][j-1]!=w[i][j+1])
                    s+=v[i][j+1];
                printf("%d",s%10);
            }
            else
                printf(".");
        printf("\n");
    }
}
