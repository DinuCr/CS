#include<iostream>
#include<fstream>
using namespace std;
ifstream f("conserve.in");
ofstream g("conserve.out");
int n,p,v[4100],t[4100],w[4100][2],i,j,s,nr;
int main()
{
    f>>p>>n;
    for(i=1;i<=n;i++)
        f>>v[i];
    for(i=1;i<=n;i++)
    {
        for(j=0;j<p;j++)
            if(w[j][0] && w[j][1]<i)
            {
                s=w[j][0]+v[i];
                if(s>w[s%p][0])
                {
                    w[s%p][0]=s;
                    t[s%p]=v[i];
                    w[s%p][1]=i;
                }
            }
         if(v[i]>w[v[i]%p][0])
        {
            w[v[i]%p][0]=v[i];
            t[v[i]%p]=v[i];
            w[v[i]%p][1]=i;
        }
    }
    cout<<w[0][0]<<'\n';
}
