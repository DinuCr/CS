#include<iostream>
#include<fstream>
using namespace std;
ifstream f("matriosca.in");
ofstream g("matriosca.out");
short v[2505][2505];
int w[2505];
int mx,x,i,j,n;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x;
        j=1;
        while(x>=w[j] && w[j]!=0)
            j++;
        w[j]=x;
        v[j][0]++;
        v[j][v[j][0]]=i;
        mx=max(mx,j);
    }
    g<<mx;
    for(i=1;i<=mx;i++)
    {
        g<<'\n'<<v[i][0]<<' ';
        for(j=1;j<=v[i][0];j++)
            g<<v[i][j]<<' ';
    }
    f.close();
    g.close();
    return 0;
}
