#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("numarare.in");
ofstream fout("numarare.out");

#define nmax 100100

const int inf = 1000000000;

int v[nmax*2];
int d[nmax*2];
int n,i,c,l,r,s;

int main()
{
    fin>>n;
    v[0]=inf;
    for(i=1; i<=n; ++i)
    {
        fin>>v[2*i-1];
        v[2*i]=inf;
    }
    n=n*2+1;
    c=0;
    d[c]=1;
    for(i=2; i<n; i+=2)
    {
        if(i+d[i]/2<=c+d[c]/2)
        {
            d[i]=min(d[c*2-i],(c-i+d[c]/2)*2+1);
        }
        if(d[i]<3)
            d[i]=3;
        if(i==n-1)
            d[i]=1;
        s=v[i-1]+v[i+1];
        l=i-d[i]/2;
        r=i+d[i]/2;

        while(l>1 && r<n-1 && s==v[r+2]+v[l-2])
        {
            l-=2;
            r+=2;
            d[i]+=4;
        }
        if(i+d[i]/2>c+d[c]/2)
            c=i;
    }
    long long ans = 0;
    for(i=2; i<=n; i+=2)
        ans+=(d[i]+1)/4;
    fout<<ans;
}
