#include <iostream>
#include <fstream>
using namespace std;
ifstream f("joc7.in");
ofstream g("joc7.out");
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},n,m,i,j,mx,k,w[27];
char v[31][31];
void bkt(int i,int j,int nr)
{
    int k,x;
    char a;
    a=v[i][j];
    w[v[i][j]-'A']=1;
    v[i][j]=0;
    mx=max(nr,mx);
    for(x=0;x<4;x++)
    {
        if(v[i+dx[x]][j+dy[x]]!=0 && w[v[i+dx[x]][j+dy[x]]-'A']==0)
        bkt(i+dx[x],j+dy[x],nr+1);
    }
    v[i][j]=a;
    w[v[i][j]-'A']=0;
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    f>>v[i][j];
    bkt(1,1,1);
    g<<mx;
}
