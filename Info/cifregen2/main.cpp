#include <iostream>

using namespace std;

int v[10];
int w[10]={2,3,5,7},n;

void bkt(int k)
{
    if(k==n+1)
    {
        for(int i=1; i<=n; ++i)
            cout<<v[i];
        cout<<'\n';
    }
    else
    {
        for(int i=0; i<4; ++i)
        {
            v[k]=w[i];
            bkt(k+1);
        }
    }
}

int main()
{
    cin>>n;
    bkt(1);
}
