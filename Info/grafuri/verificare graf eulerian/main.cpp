#include<iostream>
#include<fstream>
using namespace std;
fstream f("eulerian.in");
int ok,v[100][100],viz[100],n,i,a,b,m,w[100],ok2;
void df(int x,int t)
{
    viz[x]=1;w[x]--;w[t]--;
    int i;
    for(i=1;i<=v[x][0];i++)
    if(v[x][i]!=t)
        if(viz[v[x][i]])
            ok=false;
        else
        df(v[x][i],x);
}
int main()
{
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>a>>b;
        v[a][0]++;
        v[a][v[a][0]]=b;
        v[b][0]++;
        v[b][v[b][0]]=a;
        w[a]++;
        w[b]++;
    }
    ok2=true;
    ok=true;i=1;
    while(ok)
    {
        df(i,0);
        if(!ok)
        {ok2=false;
            break;}
        ok=false;
        for(i=1;i<=n;i++)
            if(w[i])
            {
                ok=true;
                break;
            }
    }
    for(i=1;i<=n;i++)
        if(w[i])
        ok2=false;
    if(ok2)
        cout<<"graf eulerian";
    else
        cout<<"graf non-eulerian";
}
