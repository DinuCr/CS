#include <iostream>

using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    for(i=n/2+1; 3*n>=2*i; ++i)
    {
        for(j=max(i+1,n*i/(2*i-n)); 2*n*i>=j*(2*i-n); ++j)
        {
            long long k = 1LL*n*i+1LL*n*j-1LL*2*i*j;
            if(1LL*n*i+1LL*n*j-1LL*2*i*j>=0)
                continue;
            k=k*-1;
            if(1LL*n*i*j%k!=0 || 1LL*n*i*j/k<=j || 1LL*n*i*j/k>1e9)
                continue;
            else
            {
                cout<<i<<' '<<j<<' '<<1LL*n*i*j/k;
                return 0;
            }
        }
    }
    cout<<-1;
}
