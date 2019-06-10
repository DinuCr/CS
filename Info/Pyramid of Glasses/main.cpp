#include <iostream>

using namespace std;

long double v[11][11];
int nr,n,t,i,j;

int main()
{
    cin>>n>>t;

    v[1][1]=t;

    for(i=2; i<=n; ++i)
        for(j=1; j<=i; ++j)
        {
            if(v[i-1][j]>1)
                v[i][j]+=(v[i-1][j]-1)/2;
            if(v[i-1][j-1]>1)
                v[i][j]+=(v[i-1][j-1]-1)/2;
        }
    for(i=1; i<=n; ++i)
        for(j=1; j<=i; ++j)
        if(v[i][j]>=1)
            nr++;
    cout<<nr;
}
