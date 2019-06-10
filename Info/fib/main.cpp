#include <iostream>

using namespace std;
int n,nr,v[100],w[100][100],i,j,k;
int main()
{
    cin>>n;
    nr=1;
    v[0]=0;
    v[1]=1;
    i=2;
    while(nr<=n*n)
    {
        v[i]=v[i-1]+v[i-2];
        i++;
        nr++;
    }
    i=1;j=1;
    for(k=1;k<=n*n;k++)
    {
        w[i][j]=v[k]%10;
        j++;
        if(j==n+1)
        {
            j=1;i++;
        }
    }
    for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)
        cout<<w[i][j]<<' ';
    cout<<endl;
    }
}
