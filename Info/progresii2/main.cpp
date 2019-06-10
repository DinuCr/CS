#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("progresii2.in");
ofstream fout("progresii2.out");

int t,n,v,i,j,lim;
long long ans;

void bs(int ls,int ld)
{
    if(ls>ld)
        return;
    int m = (ls+ld)>>1;
    if(1LL*n*m-m<=v)
    {
        lim=m;
        bs(m+1,ld);
    }
    else
    bs(ls,m-1);
}

int main()
{
    fin>>t;
    while(t--)
    {
        fin>>v>>n;
        if(n==1)
            fout<<v<<'\n';
        else
        {
            ans = 0;
            lim=0;
            bs(1,v);
            ans = 1LL*v*lim+1LL*(1+lim)*lim/2-1LL*n*(1+lim)*lim/2;
            fout<<ans<<'\n';
        }
    }
}
