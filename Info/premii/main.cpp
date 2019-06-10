#include<iostream>
#include<fstream>
using namespace std;
ifstream f("premii.in");
ofstream g("premii.out");
int v[201][201],i,j,s,n,k,ok,p,r;
int main()
{
    f>>n>>k;
    for(i=1;i<=k;i++)
    {
        p=0;
        r=i;
        while(k*p+r<=n)
        {
            v[i][p]=k*p+r;
            v[i][n/k]+=v[i][p];
            p++;
            r++;
            if(r>k)
                r=1;
        }
    }
    ok=true;
    for(i=2;i<=k;i++)
        if(v[i][n/k]!=v[i-1][n/k])
        {
            ok=false;
            break;
        }
    if(ok==true)
    for(i=1;i<=k;i++)
    {
        for(j=0;j<n/k;j++)
            g<<v[i][j]<<' ';
        g<<'\n';
    }
    else
        g<<'0';
    return 0;
}
