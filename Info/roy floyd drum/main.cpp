#include <iostream>
#include<fstream>
using namespace std;
int n,i,j,v[100][100],m[100][100],k,p,x1,y1;
void drum(int i,int j)
{
    int k;
    cout<<j<<' ';
    while(j!=i)
    {
        for(k=1;k<=n;k++)
        if(m[i][j]-m[i][k]==v[k][j])
        {
            j=k;
            cout<<j<<' ';
            break;
        }
    }
}

int main()
{
    ifstream f("graf.in");
    f>>n>>x1>>y1;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        v[i][j]=10000;
        m[i][j]=10000;
    }
    for(i=1;i<=n;i++)
    {
        v[i][i]=0;
        m[i][i]=0;
    }
    while(f>>i>>j>>p)
    {
        v[i][j]=p;
        m[i][j]=p;
    }
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(m[i][j]>m[i][k]+m[k][j])
        m[i][j]=m[i][k]+m[k][j];
    drum(x1,y1);
}
