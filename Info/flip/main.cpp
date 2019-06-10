#include<iostream>
#include<fstream>
using namespace std;
ifstream f("flip.in");
ofstream g("flip.out");
int i,j,w[20],v[20][20],n,m,s,S,mx;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    f>>v[i][j];
    while(!w[0])
    {
        i=m;S=0;
        while(w[i]==1)
        {
            w[i]=0;
            i--;
        }
        w[i]=1;
        for(i=1;i<=n;i++)
        {
            s=0;
            for(j=1;j<=m;j++)
                if(w[j]==1)
                s+=v[i][j];
                else
                s-=v[i][j];
            if(s<0)
                s*=-1;
            S+=s;
        }
        mx=max(S,mx);
    }
    g<<mx;
    g.close();
    cout<<s;
}
