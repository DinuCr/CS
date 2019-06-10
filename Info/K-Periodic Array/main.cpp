#include <iostream>

using namespace std;

int n,k,v[1000],mn,i,j,p,nr,w[1000];

int main()
{
    cin>>n>>k;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    mn=100000;
    for(i=1; i<=n; i+=k)
    {
        for(j=0; j<k; ++j)
            w[j]=0;
        nr=0;
        for(j=1; j<=n; j+=k)
            for(p=0; p<k; ++p)
                if(v[j+p]!=v[i+p])
                {
                    w[p]++;
                    ++nr;
                }
        for(j=0; j<k; ++j)
            if(n/k-w[j]<w[j])
                nr=nr-w[j]+n/k-w[j];
        mn=min(mn,nr);
    }
    cout<<mn;
}
