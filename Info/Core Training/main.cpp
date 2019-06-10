#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream fin("input.in");
ofstream fout("output.out");

double v[100];
double rez;
int n,i;

bool check(double ans,double u)
{
    for(int i=1; i<=n; ++i)
        if(v[i]<ans)
            u-=ans-v[i];
    if(u<0)
        return 0;
    return 1;
}

int main()
{
    int t,cnt = 0;
    fin>>t;
    while(t--)
    {
        ++cnt;
        int k;
        double u;
        fout<<"Case #"<<cnt<<": ";
        fin>>n>>k>>u;
        for(i=1; i<=n; ++i)
            fin>>v[i];
        sort(v+1,v+n+1);
        int step = 1;
        double ans = 0;
        for( ; step<=1e8; step<<=1);
        for( ; step; step>>=1)
        if(ans + (double)step/1e8<=1)
        {
            if(check(ans+(double)step/1e8,u))
                ans+=(double)step/1e8;
        }
        double rez = 1;
        for(i=1; i<=n; ++i)
        {
            if(v[i]<ans)
            {
                u-=ans-v[i];
                v[i]=ans;
            }
        }
        if(u>0)
        {
            sort(v+1,v+n+1);
            for(i=1; i<=n; ++i)
            {
                double a=v[i];
                v[i]=min(1.0,u+v[i]);
                u-=v[i]-a;
            }
        }
        for(i=1; i<=n; ++i)
            rez*=v[i];
        fout<<setprecision(10)<<fixed<<rez<<'\n';
    }
}
