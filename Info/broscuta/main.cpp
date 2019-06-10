#include <iostream>
#include<fstream>
using namespace std;
ifstream f("broscuta.in");
ofstream g("broscuta.out");
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1},ok=1,k,i,j,nr=0,m,i0,j0,v[160000][3],a[400][400];
void drum(int i0,int j0)
{
    int n,i,j,ok,k;
    n=1;
    v[n][0]=i0;
    v[n][1]=j0;
    v[n][2]=1;
    ok=false;
    if(v[n][0]==1 || v[n][0]==m || v[n][1]==1 || v[n][1]==m)
        ok=true;
    for(i=1;i<=n && !ok;i++)
    {
        for(k=0;k<4;k++)
        if(a[v[i][0]+dx[k]][v[i][1]+dy[k]]==-1)
        {
            a[v[i][0]+dx[k]][v[i][1]+dy[k]]=v[i][2]+1;
            n++;
            v[n][0]=v[i][0]+dx[k];
            v[n][1]=v[i][1]+dy[k];
            v[n][2]=v[i][2]+1;
            if(v[n][0]==1 || v[n][0]==m || v[n][1]==1 || v[n][1]==m)
                {ok=true;
                break;}
        }
    }
    if(ok){
    cout<<v[n][2]<<'\n';
    i=v[n][0];
    j=v[n][1];
    cout<<i<<' '<<j<<'\n';
    while(a[i][j]!=1)
    {
        for(k=0;k<4;k++)
        if(a[i+dx[k]][j+dy[k]]==a[i][j]-1)
        {
            i+=dx[k];
            j+=dy[k];
            break;
        }
        cout<<i<<' '<<j<<'\n';
    }}
        else
        cout<<"nu ajung";
}
int main()
{
    f>>m>>i0>>j0;
    a[i0][j0]=1;
    while(!f.eof()) {f>>i>>j;a[i][j]=-1;}
    drum(i0,j0);
}
