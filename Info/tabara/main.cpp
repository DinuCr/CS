#include <iostream>
#include<fstream>
#include<cmath>
using namespace std;
ifstream f("tabara.in");
ofstream g("tabara.out");
int n,v[10001],s,st,nr,ok,x,i,p;
void qsort(int ls,int ld)
{
    int m,i,j,z;
    m=(ls+ls)/2;
    i=ls;
    j=ld;
    z=v[m];
    do
    {
        while(v[i]<z)
            i++;
        while(v[j]>z)
            j--;
        if(i<=j)
        {
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(i<ld)
        qsort(i,ld);
    if(j>ls)
        qsort(ls,j);
}
int caut (int s, int d)
{
    int m;
    m =(s+d)/2;
    if (x==v[m])
        return m;
    else
    if(abs(d-s)==2 || abs(d-s)==1)
    return 0;
    if (x<v[m])
        return caut(s,m-1);
    else
        return caut(m+1,d);
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>v[i];
        if(v[i]%n==0)
        {
            ok=true;
            p=i;
        }
        st+=v[i];
    }
    if(ok)
        g<<"1 "<<v[p]/n<<'\n'<<v[p]<<'\n'<<st-v[p];
    else
    {
    qsort(1,n);
    s=st;i=1;nr=n;
    while(s%n!=0)
    {
        x=s%n;
        p=caut(1,n);
        if(v[p]==x)
        {
            s-=v[p];
            v[p]=0;
            nr--;
            ok=true;
            break;
        }
        else
        {
            s-=v[i];
            v[i]=0;
            nr--;
        }
    }
    if(ok)
    {
        g<<nr<<' '<<s/n<<'\n';
        for(i=1;i<=n;i++)
            if(v[i])
            g<<v[i]<<' ';
        g<<'\n'<<st-s;
    }
    }
    f.close();
    return 0;
}
