#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
ifstream f("linie.in");
ofstream g("linie.out");
int w[20],v[20],m1,m2,m[20][20],n,i,j,s,mn;
void tipar()
{
    int i,j,s1=0,s2=0;
    for(i=1;i<=n;i++)
    for(j=1;j<=v[i];i++)
    {
        s1+=m[i][j];
    }
    s2=s-s1;
    if(abs(s1-s2)<mn)
    {
        mn=abs(s1-s2);
        m1=s1;
        m2=s2;
        for(i=1;i<=n;i++)
            w[i]=v[i];
    }
}
void bkt(int k)
{
    int l;
    if(k==n)
        tipar();
    else
    {
        for(l=1;l<n;l++)
        {
            v[k]=l;
            bkt(k+1);
        }
    }
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        f>>m[i][j];
    s+=m[i][j];
    }
    mn=s;
    bkt(1);
    cout<<m1<<'\n'<<m2<<'\n';
    for(i=1;i<=n;i++)
        cout<<w[i]<<' ';
    f.close();
    g.close();
    return 0;
}
