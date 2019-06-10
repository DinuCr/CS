#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("mafia.in");
ofstream fout("mafia.out");

long long vx,n,m,x,s,i,j;
long double ans;

int main()
{
    int t;
    fin>>t;
    while(t--)
    {
        ans=1;
        s=0;
        int p;
        fin>>n>>m>>x;
        for(i=1; i<=n; ++i)
            if(i==x)
            {
                fin>>vx;
                s+=vx;
            }
            else
            {
                fin>>p;
                s+=p;
            }
        i=s-vx-m+1;
        j=s-vx+1;
        while(i<=s-m || j<=s)
        {
            if(i<=s-m)
            {
                ans*=i;
                ++i;
            }
            if(j<=s && (ans>100000 || i>s-m))
            {
                ans/=j;
                ++j;
            }
        }
        ans = 1-ans;
        fout<<setprecision(17)<<fixed<<ans<<'\n';
    }
}
