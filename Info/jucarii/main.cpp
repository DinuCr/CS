#include<iostream>
#include<fstream>
using namespace std;
int n,v[11],k,p,x;
ifstream f("jucarii.in");
ofstream g("jucarii.out");
void subsir();

void bkt(int k)
{
if(x<p)
{
    int l,i,ok;
    if(k==n+1)
        subsir();
    else
    for(l=1;l<=n;l++)
    {
        ok=true;
        for(i=1;i<k;i++)
            if(v[i]==l)
            ok=false;
        if(ok)
            {
                v[k]=l;
                bkt(k+1);
            }
    }
}
}
void subsir()
{
    int w[11],mx,i,j,mx2=0;
    w[1]=1;
    for(i=2;i<=n;i++)
    {
        mx=0;
        for(j=1;j<i;j++)
            if(v[i]>v[j])
            mx=max(mx,w[j]);
        w[i]=mx+1;
        mx2=max(w[i],mx2);
    }
    if(mx2>=k)
        x++;
    if(x==p)
        for(i=1;i<=n;i++)
        g<<v[i]<<' ';

}

int main()
{
    f>>n>>k>>p;
    bkt(1);
}
