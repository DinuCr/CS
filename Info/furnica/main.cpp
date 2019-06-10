#include<iostream>
#include<fstream>
using namespace std;
ifstream f("furnica.in");
ofstream g("furnica.out");
int v[203][203],i,j,dx[9]={0,-1,-1,0,1,1,1,0,-1},dy[9]={0,0,1,1,1,0,-1,-1,-1},x,s,nr,n,k,z,w[203][203],mx;
int main()
{
    f>>n>>k;
    for(i=0;i<=n+1;i++)
    {
        v[i][n+1]=-1;
        v[i][0]=-1;
        v[0][i]=-1;
        v[n+1][i]=-1;
    }
    i=1;
    j=1;
    s=2;
    w[1][1]=1;
    for(z=1;z<=k;z++)
    {
        f>>x;
        if(v[i+dx[x]][j+dy[x]]!=-1)
        {
            i+=dx[x];
            j+=dy[x];
            w[i][j]++;
            if(v[i][j]!=-2)
            {
                s+=(i+j)%6;
                v[i][j]=-2;
            }
        }
    }
    mx=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(w[i][j]>mx)
        {
            mx=w[i][j];
            nr=1;
        }
        else
            if(w[i][j]==mx)
            nr++;
    g<<s<<' '<<nr;
    f.close();
    g.close();
    return 0;
}
