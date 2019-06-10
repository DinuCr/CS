#include<iostream>
#include<fstream>
using namespace std;
ifstream f("7segmente.in");
ofstream g("7segmente.out");
int v[20],w[20],v1[20],i,ok,a,bs,b,n,s;
bool cond(int k)
{
    int i,s=0;
    for(i=1;i<=k;i++)
        s+=w[v[i]];
    if(s>b)
        return 0;
    else
        return 1;
}
int tipar()
{
    int s=0,i;
    for(i=1;i<=n;i++)
        s+=w[v[i]];
    if(s<=b && ok==true)
    {
        ok=false;
        for(i=1;i<=n;i++)
        {
            g<<v[i];
            v[i]=0;
        }
    }
}
void bkt(int k)
{
    int l;
    if(ok==true)
    {
        if(k==n+1)
            tipar();
        else
        {
            i=1;
            while(v[i]==v1[i] && i<=k-1)
                i++;
            if(i==k)
            for(l=v1[k];l>0;l--)
            {
                v[k]=l;
                if(cond(k))
                    bkt(k+1);
            }
            else
                for(l=9;l>0;l--)
            {
                v[k]=l;
                if(cond(k))
                    bkt(k+1);
            }
        }
    }
}
int main()
{
    f>>a>>b;
    while(a!=0)
    {
        i++;
        v1[i]=a%10;
        a/=10;
    }
    n=i;
    w[1]=2;
    w[2]=5;
    w[3]=5;
    w[4]=4;
    w[5]=5;
    w[6]=6;
    w[7]=3;
    w[8]=7;
    w[9]=6;
    for(i=1;i<=n;i++)
    {
        s+=w[v1[i]];
    }
    g<<s<<' ';
    for(i=1;i<n/2;i++)
    {
        v1[i]=v1[n-i+1];
    }
    ok=true;
    bkt(1);
    f.close();
    g.close();
    return 0;
}
