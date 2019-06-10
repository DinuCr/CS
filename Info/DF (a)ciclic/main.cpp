#include<iostream>
#include<fstream>
using namespace std;
fstream f("df.in");
int ok,v[100][100],viz[100],n,i,a,b;
void df(int x,int t)
{
    viz[x]=1;
    cout<<x<<' ';
    int i;
    for(i=1;i<=v[x][0];i++)
    if(v[x][i]!=t)
    {
        if(viz[v[x][i]])
            ok=false;
        else
        df(v[x][i],x);
    }
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        v[a][0]++;
        v[a][v[a][0]]=b;
        v[b][0]++;
        v[b][v[b][0]]=a;
    }
    ok=true;
    df(1,0);
    if(ok)
        cout<<"aciclic";
    else
        cout<<"ciclic";
}
