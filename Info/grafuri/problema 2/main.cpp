#include<iostream>
#include<fstream>
using namespace std;
ifstream f("2.in");
int v[100][100],x,y,c[100],viz[100],p,i,ok,u,n,a,b,k;
void qsort(int ls,int ld,int p)
{
    int m,i,j,z;
    m=(ls+ls)/2;
    i=ls;
    j=ld;
    z=v[p][m];
    do
    {
        while(v[p][i]<z)
            i++;
        while(v[p][j]>z)
            j--;
        if(i<=j)
        {
            swap(v[p][i],v[p][j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(i<ld)
        qsort(i,ld,p);
    if(j>ls)
        qsort(ls,j,p);
}
int main()
{
    f>>n>>x>>y;
    while(!f.eof())
    {
        f>>a>>b;
        v[a][0]++;
        v[a][v[a][0]]=b;
        v[b][0]++;
        v[b][v[b][0]]=a;
    }
    for(i=1;i<=n;i++)
    qsort(1,v[i][0],i);
    c[1]=x;
    u=1;
    p=1;
    viz[x]=1;
    ok=true;
    if(c[u]==y)
        ok=false;
    while(p<=u && ok)
    {
        for(i=1;i<=v[c[p]][0];i++)
        if(!viz[v[c[p]][i]])
        {
            u++;
            c[u]=v[c[p]][i];
            viz[v[c[p]][i]]=viz[c[p]]+1;
            if(c[u]==y)
            {
                ok=false;
                break;
            }
        }
        p++;
    }
    while(viz[y]!=1)
    {
        k++;
        c[k]=y;
        for(i=1;i<=v[y][0];i++)
        if(viz[v[y][i]]==viz[y]-1)
        {
            y=v[y][i];
            break;
        }
    }
    for(i=k;i>0;i--)
        cout<<c[i]<<' ';
    f.close();
}