#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("blaturi.in");
ofstream fout("blaturi.out");

#define nmax 100100

int v[nmax];
int d1[nmax];
int d2[nmax];
int ans = 1e9;
int i,n,a1,a2,b1,b2,a,b;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    fin>>a1>>a2;
    fin>>b1>>b2;
    for(i=1; i<=n; ++i)
        d1[i]=d1[i-1]+v[i]*a1;
    for(i=n; i>=0; --i)
        d2[i]=d2[i+1]+v[i+1]*b1;
    for(i=0; i<=n; ++i)
        if(i>n-i+1)
        {
            a=i;
            b=n-i+1;
            ans=min(ans,d1[i]+d2[i]+(a-b)*a2);
        }
        else
        if(n-i>i+1)
        {
            a=i+1;
            b=n-i;
            ans=min(ans,d1[i]+d2[i]+(b-a)*b2);
        }
        else
            ans=min(ans,d1[i]+d2[i]);
    fout<<ans;
}
