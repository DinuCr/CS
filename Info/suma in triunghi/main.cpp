#include <iostream>
#include <fstream>
using namespace std;
ifstream f("sumatr.in");
int v[100][100],w[100][100],i,j,n,mx,j2;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    for(j=1;j<=i;j++)
    f>>v[i][j];
    for(i=1;i<=n;i++)
    for(j=1;j<=i;j++)
    {
        w[i][j]=max(w[i-1][j-1],w[i-1][j])+v[i][j];
        if(w[i][j]>mx)
            mx=w[i][j],j2=j;
    }
    cout<<mx<<'\n';
    j=j2;
    while(i>0)
    {
        cout<<v[i][j]<<' ';
        if(w[i][j]==v[i][j]+w[i-1][j-1])
            i--,j--;
        else
            i--;
    }
}
