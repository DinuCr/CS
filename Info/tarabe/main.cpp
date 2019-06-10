#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("tarabe.in");
ofstream fout("tarabe.out");

#define nmax 200010

int a[nmax];
int b[nmax];
long long sum,ans;

int main()
{
    int n,k,i;
    fin>>n>>k;
    for(i=1; i<=n; ++i)
        fin>>b[i]>>a[i];
    long long step;
    for(step = 1; step<=1e18; step<<=1);
    ans = 1e18;
    long long curr;
    for( ; step; step>>=1)
        if(ans-step>0)
        {
            curr = 0;
            for(i=1; i<=n; ++i)
            {
                if(ans-step>=a[i])
                curr+=(1LL*ans-step-a[i])/b[i]+1;
                if(curr>k)
                    break;
            }
            if(curr>=k)
                ans-=step;
        }
    curr = 0;
    for(i=1; i<=n; ++i)
    if(ans>=a[i])
    {
        curr+=(ans-step-a[i])/b[i]+1;
        sum+=1LL*((1LL*ans-step-a[i])/b[i]+1)*(1LL*a[i]+a[i]+(1LL*ans-step-a[i])/b[i]*b[i])/2;
    }
    sum-=ans*(curr-k);
    fout<<sum;
}
