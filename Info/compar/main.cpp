#include<iostream>
#include<fstream>
using namespace std;
ifstream f("compar.in");
ofstream g("compar.out");
int w[100002],i,n,ls,ld;
char v[100001];
int main()
{
    while(!f.eof())
    {
        n++;
        f>>v[n];
    }
    v[n]=0;
    n--;
    ls=1;
    ld=n+1;
    for(i=2;i<=n;i++)
    {
        if(v[i]=='<' && v[i-1]=='>')
        w[i]=ls++;
        else
        if(v[i-1]=='<' && v[i]=='>')
        w[i]=ld--;
    }
    if(v[1]=='>')
        w[1]=ld--;
    else
        w[1]=ls++;
    for(i=2;i<=n+1;i++)
    if(w[i]==0)
    {
        if(v[i-1]=='<')
        w[i]=ls++;
        else
        w[i]=ld--;
    }
    g<<n+1<<endl;
    for(i=1;i<=n+1;i++)
        g<<w[i]<<' ';
    f.close();
    g.close();
    return 0;
}
