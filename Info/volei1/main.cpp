#include<iostream>
#include<fstream>
using namespace std;
ifstream f("volei1.in");
ofstream g("volei1.out");
int v[4002],w[2001],n,m,i,j,mn,x,ok,p,q,nr;
int main()
{
    f>>n;
    n*=2;
    for(i=1;i<=n;i+=2)
        f>>v[i];
    n++;
    v[n]=v[1];
    f>>m;
    for(i=1;i<=m;i++)
        f>>w[i];
    ok=true;
    while(ok)
    {
        i=2;
        while(v[i]!=0 && i<n)
        {
            i+=2;
        }
        x=max(v[i-1],v[i+1]);
        p=i;
        j=i+2;
        for(i=j;i<=n;i+=2)
        if(v[i]==0)
        {
           if(max(v[i-1],v[i+1])<x)
                {
                    x=max(v[i-1],v[i+1]);
                    p=i;
                }
        }
        i=1;
        while((w[i]==0 || w[i]<=x) && i<=m)
            i++;
        mn=w[i];
        q=i;
        if(i==m+1)
            break;
        for(i=q;i<=m;i++)
        {
            if(w[i]>x)
                if(w[i]<mn)
                {
                    q=i;
                    mn=w[i];
                }
        }
        if(mn<=x)
            break;
        v[p]=-mn;
        w[q]=0;
        nr++;
    }
    g<<nr<<'\n';
    for(i=1;i<n;i++)
        if(v[i]!=0)
        g<<v[i]<<' ';
    f.close();
    g.close();
    return 0;
}
