#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream f("secv2.in");
ofstream g("secv2.out");

int x,n,k,mn,i,s,l,mx,i0,i1;
int v[51000];


int main()
{
    f>>n>>k;
    mx=-2000000000;
    mn=0;
    l=0;
    for(i=1; i<=n; ++i)
    {
        f>>x;
        s+=x;
        v[i]=s;
        if(i>=k)
        {
            if(s-mn>mx)
            {
                i0=l+1;
                i1=i;
                mx=s-mn;
            }
            if(i>k)
            {
                if(v[i-k]<mn)
                {
                    l=i-k;
                    mn=v[i-k];
                }
            }
        }
    }
    g<<i0<<' '<<i1<<' '<<mx;
}
