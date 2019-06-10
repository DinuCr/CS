#include<iostream>
#include<fstream>
using namespace std;
ifstream f("v.in");
ofstream g("v.out");
long v[103][103],n,i,m,j,k,s,l,c,mx,i1,x;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    f>>v[i][j];
    mx=v[1][1]+v[2][2]+v[1][3];
    c=1;l=2;
    for(k=2;k<=n;k++)
    {
        for(j=1;j<=m-2*k+2;j++)
        {
            s=0;
            for(i1=1,x=j;i1<k;i1++,x++)
                s+=v[i1][x];
            for(i1=k,x=j+k-1;i1>0;i1--,x++)
                s+=v[i1][x];
            if(s>mx){mx=s;l=k;c=j;}
        }
    }
    g<<mx<<' '<<c<<' '<<l;
    f.close();
    g.close();
    return 0;
}
