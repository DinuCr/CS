#include<iostream>
using namespace std;
int v[100][100],n;
bool intersectie(int x,int y)
{
    int i,j,ok;
    ok=false;
    for(i=1;i<=v[x][0];i++)
    for(j=1;j<=v[y][0];j++)
    if(v[x][i]==v[y][j])
    {
        ok=true;
        break;
    }
    return ok;
}
void reuniune(int x,int y)
{
    int i,j,ok;
    for(i=1;i<=v[x][0];i++)
    {
        ok=true;
        for(j=1;j<=v[y][0];j++)
        if(v[x][i]==v[y][j])
        {
            ok=false;
            break;
        }
        if(ok==true)
        {
            v[y][0]++;
            v[y][v[y][0]]=v[x][i];
        }
    }
    v[x][0]=0;
}
void prelucrare()
{
    int i,j;
    i=1;
    for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++)
    {
        if(intersectie(i,j)>0)
            reuniune(i,j);
    }
}
void citire()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>v[i][1]>>v[i][2];
        v[i][0]=2;
    }
}
void afisare()
{
    int i,j;
    for(i=1;i<=n;i++)
    if(v[i][0]!=0)
    {
        for(j=1;j<=v[i][0];j++)
        cout<<v[i][j]<<' ';
        cout<<'\n';
    }
}
int main()
{
    citire();
    prelucrare();
    afisare();
}
