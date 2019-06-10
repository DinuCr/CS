#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("3secv.in");
ofstream fout("3secv.out");

long long n,p1,p2,ans1,ans2,i,j;
long long v[1000100];
long long w[1000100];
long long s,ans;

inline long long fct(int i1,int i2)
{
    return max(w[i1],max(w[i2]-w[i1],w[n]-w[i2])) - min(w[i1],min(w[i2]-w[i1],w[n]-w[i2]));
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
        w[i]=v[i]+w[i-1];
    }
    ans=w[n];
    j=2;
    for(i=1; i<n; ++i)
    {
        if(i==j)
            ++j;
        while(fct(i,j)>fct(i,j+1))
            ++j;
        if(fct(i,j)<ans)
        {
            ans=fct(i,j);
            ans1=i;
            ans2=j;
        }
    }

    fout<<ans1<<' '<<ans2;
}
