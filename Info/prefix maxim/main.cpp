#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int mx,i,j,n,m,k,dx[8]={0,0,1,-1,1,1,-1,-1},dy[8]={1,-1,0,0,-1,1,1,-1};
char s[100],v[100][100];
void drum(int i,int j,int nr)
{
    if(nr==k)
    {
        mx=k;
        return;
    }
    else
    {
        int c=v[i][j];
        v[i][j]=0;
        for(int p=0;p<8;p++)
        {
            if(v[i+dx[p]][j+dy[p]]==s[nr])
                drum(i+dx[p],j+dy[p],nr+1);
        }
        v[i][j]=c;
        mx=max(mx,nr);
    }
}
int main()
{
    ifstream f("prefix.in");
    f>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    f>>v[i][j];
    f.getline(s,100);
    f.getline(s,100);
    k=strlen(s);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(mx<k)
    {
        if(v[i][j]==s[0])
        drum(i,j,1);
    }
    for(i=0;i<mx;i++)
        cout<<s[i];
}
